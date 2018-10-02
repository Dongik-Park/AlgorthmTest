#include <cstdio>
#include <vector>
#define MAX_N 1000
#define MAX_LOC 1000
#define MIN_LOC -1000
using namespace std;

// ���� ����ü
struct Atom{
	int row;
	int col;
	int energy;
	int dir;
};
// ���ڸ��
vector<Atom> list;
// ���� �̵� ǥ���� map
int map[MAX_LOC - (MIN_LOC) + 1][MAX_LOC - (MIN_LOC) + 1];
// ���� �Ҹ� ���� �迭
bool isActive[MAX_N];
// ��, ��, ��, ��
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
// �迭 index �˻�
bool inRange(int row, int col){
	if (row >= 0 && row <= MAX_LOC + MAX_LOC && col >= 0 && col <= MAX_LOC + MAX_LOC)
		return true;
	return false;
}
// ���� ���� Ȯ��
bool isFinished(int N){
	int cnt = 0;
	for (int i = 0; i < N; ++i){
		if (cnt > 1)
			return false;
		if (isActive[i])
			++cnt;
	}
	return true;
}
// map�� ���� �Ҹ� ���� �迭 �ʱ�ȭ �� �ʱⰪ ����
void init(int N){
	for (int i = 0; i <= MAX_LOC + MAX_LOC; ++i)
		for (int j = 0; j <= MAX_LOC + MAX_LOC; ++j)
			map[i][j] = 0;
	for (int i = 0; i < N; ++i)
		isActive[i] = true;
	for (int i = 0; i < list.size(); ++i)
		map[list[i].row][list[i].col] = 1;
}
// ���� ������ ��ǥ�� ���ڰ� ������ ���(���� �̵� �� 1�ʹ̸����� �Ҹ��ϴ� ���) ������ ��ǥ�� �߰��ϰ� ���� ���� �������� �߰� �� �Ҹ��Ų��.
void findAdjacent(int * sum){
	for (int i = 0; i < list.size(); ++i){
		if (!isActive[i])
			continue;
		int n_row = list[i].row + dx[list[i].dir];
		int n_col = list[i].col + dy[list[i].dir];
		if (inRange(n_row, n_col) && map[n_row][n_col] > 0){
			for (int j = 0; j < list.size(); ++j){
				if (isActive[j] &&
					list[j].row == n_row &&
					list[j].col == n_col &&
					// ���� �ݴ� ���� ������ ���
					(-1 * dx[list[j].dir]) == dx[list[i].dir] &&
					(-1 * dy[list[j].dir]) == dy[list[i].dir]) {
					// ������ ���� �ΰ��� ������ ����
					*sum += list[i].energy;
					*sum += list[j].energy;
					// �� ������ index 1 ���� �ʱ�ȭ
					--map[list[i].row][list[i].col];
					--map[list[j].row][list[j].col];
					// �� ���� �Ҹ�
					isActive[i] = false;
					isActive[j] = false;
				}
			}
		}
	}
}
// ���ڵ��� ���⿡ �°� 1ĭ�� �̵���Ų��.
void moveAtoms(){
	for (int i = 0; i < list.size(); ++i){
		// ���� ���ڰ� �Ҹ�Ǿ��� ��� 
		if (!isActive[i])
			continue;
		// ���� �湮 map index �ʱ�ȭ
		--map[list[i].row][list[i].col];
		// list �ʱ�ȭ
		int n_row = list[i].row + dx[list[i].dir];
		int n_col = list[i].col + dy[list[i].dir];
		// ���� ������ ��ǥ�� ���
		if (inRange(n_row, n_col)){
			list[i].row = n_row;
			list[i].col = n_col;
			++map[n_row][n_col];
		}
		// ���� ���� ��ǥ�� ����� ��� �Ҹ�
		else
			isActive[i] = false;
	}
}
void checkDuplicate(int *sum){
	// �ΰ� �̻��� ���ڰ� �湮�� ��ǥ ���
	vector<pair<int, int>> cur_list;
	// �ΰ� �̻� �湮�� ��带 ã�´�.
	for (int i = 0; i < list.size(); ++i)
		if (map[list[i].row][list[i].col] > 1){
			cur_list.push_back(make_pair(list[i].row, list[i].col));
		}
	// �ΰ� �̻� �湮�� ��ǥ�� �����ϴ� ���ڵ鿡 ���� �������� ���ϰ� map�� �ʱ��� �� �Ҹ��Ѵ�. 
	for (int i = 0; i < cur_list.size(); ++i){
		int cur_row = cur_list[i].first;
		int cur_col = cur_list[i].second;
		for (int j = 0; j < list.size(); ++j)
			if (isActive[j] && cur_row == list[j].row && cur_col == list[j].col){
				--map[list[j].row][list[j].col];
				*sum += list[j].energy;
				isActive[j] = false;
			}
	}
}
int solve(int N){
	int sum = 0;
	// ���� �ʱ�ȭ 
	init(N);

	while (!isFinished(N)){
		// ������ ���� ����
		findAdjacent(&sum);
		// ���� �̵�
		moveAtoms();
		// �ߺ��� ���� �Ҹ�
		checkDuplicate(&sum);
	}

	return sum;
}

int main(){

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		int N;
		scanf("%d", &N);
		// ���� ��� �Է�
		while (!list.empty()) list.pop_back();
		for (int i = 0; i < N; ++i){
			Atom atom;
			scanf("%d %d %d %d", &atom.col, &atom.row, &atom.dir, &atom.energy);
			atom.col += MAX_LOC;
			atom.row += MAX_LOC;
			list.push_back(atom);
		}
		// ��� ���
		printf("#%d %d\n", test_case, solve(N));
	}

	return 0;
}