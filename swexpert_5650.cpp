#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 100
#define MAX_HOLE 5
using namespace std;
// ��Ȧ ����ü
struct Wormhole{
	int num;
	int row;
	int col;
};

vector<Wormhole> holes; // ��Ȧ ���
int map[MAX_N][MAX_N];  // �ɺ� �� 
int N; // �Ѻ��� ����
int dx[4] = {-1, 1, 0, 0}; // �����¿�
int dy[4] = {0, 0, -1, 1};

bool inRange(int row, int col){
	if (row >= 0 && row < N && col >= 0 && col < N)
		return true;
	return false;
}
// �� ����� ���� �����ϵ� ���� ������ �ݴ����(180)�� ��� ���� ��η� ���ư��Ƿ� ����
bool changeDir(int row, int col, int * dir){
	bool isFinished = false;
	switch (map[row][col])
	{
	case 1: 
		if (*dir == 1 || *dir == 2)	*dir = (*dir + 2) % 4;
		else					    isFinished = true;
		break;
	case 2:
		if (*dir == 0 || *dir == 2)	*dir = (*dir + 3) % 4;
		else					    isFinished = true;
		break;
	case 3:
		if (*dir == 0 || *dir == 3)	*dir = (*dir + 2) % 4;
		else					    isFinished = true;
		break;
	case 4:
		if (*dir == 1 || *dir == 3)	*dir = (*dir + 1) % 4;
		else					    isFinished = true;
		break;
	case 5:
		isFinished = true;
		break;
	}
	return isFinished;
}
// ���� ��ǥ�� ���� �������� ����
int loop(int row, int col, int dir){
	int cnt = 0;
	int n_row = row;
	int n_col = col;

	while (true){
		n_row += dx[dir];
		n_col += dy[dir];
		// ���ŵ� ��ǥ�� ���� �ε��� ��� ���� ���� x 2 + 1 �� ����
		if (!inRange(n_row, n_col)){
			cnt = (cnt * 2) + 1;
			break;
		}
		// ����� ��� ���� ��ȯ �� ���� �߰�, �ݴ� ������ ��� ����
		if (map[n_row][n_col] >= 1 && map[n_row][n_col] <= 5){
			if (changeDir(n_row, n_col, &dir)){
				cnt = (cnt * 2) + 1;
				break;
			}
			++cnt;
		}
		// ��Ȧ�� ��� ��ǥ ����
		else if (map[n_row][n_col] >= 6 && map[n_row][n_col] <= 10){
			for (int i = 0; i < holes.size(); ++i)
				if (holes[i].num == map[n_row][n_col] && (holes[i].row != n_row || holes[i].col != n_col)){
					n_row = holes[i].row;
					n_col = holes[i].col;
					break;
				}
		}
		// ���� ����
		if ((n_row == row && n_col == col) || map[n_row][n_col] == -1) break;
	}
	return cnt;
}

int solve(){
	int max_val = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (map[i][j] == 0) // ������� ���� ��� Ȯ���Ѵ�.
				for (int dir = 0; dir < 4; ++dir)
					max_val = max(max_val, loop(i, j, dir));
			
	return max_val;
}
// ��Ȧ ��� �ʱ�ȭ
void init(){ 
	while (!holes.empty()) holes.pop_back();
}

int main(){

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d", &N);
		init();
		// �ɺ� �� �� ��Ȧ ��� �Է�
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j){
				scanf("%d", &map[i][j]);
				if (map[i][j] >= 6 && map[i][j] <= 10){
					Wormhole hole;
					hole.num = map[i][j];
					hole.row = i;
					hole.col = j;
					holes.push_back(hole);
				}
			}
		// ��� ���
		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}