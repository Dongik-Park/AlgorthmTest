#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 100
#define MAX_HOLE 5
using namespace std;
// 웜홀 구조체
struct Wormhole{
	int num;
	int row;
	int col;
};

vector<Wormhole> holes; // 웜홀 목록
int map[MAX_N][MAX_N];  // 핀볼 맵 
int N; // 한변의 길이
int dx[4] = {-1, 1, 0, 0}; // 상하좌우
int dy[4] = {0, 0, -1, 1};

bool inRange(int row, int col){
	if (row >= 0 && row < N && col >= 0 && col < N)
		return true;
	return false;
}
// 각 블록의 방향 갱신하되 현재 방향의 반대방향(180)일 경우 같은 경로로 돌아가므로 종료
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
// 현재 좌표와 방향 기준으로 점검
int loop(int row, int col, int dir){
	int cnt = 0;
	int n_row = row;
	int n_col = col;

	while (true){
		n_row += dx[dir];
		n_col += dy[dir];
		// 갱신된 좌표가 벽에 부딪힐 경우 현재 점수 x 2 + 1 후 종료
		if (!inRange(n_row, n_col)){
			cnt = (cnt * 2) + 1;
			break;
		}
		// 블록일 경우 방향 전환 및 점수 추가, 반대 방향일 경우 종료
		if (map[n_row][n_col] >= 1 && map[n_row][n_col] <= 5){
			if (changeDir(n_row, n_col, &dir)){
				cnt = (cnt * 2) + 1;
				break;
			}
			++cnt;
		}
		// 웜홀일 경우 좌표 갱신
		else if (map[n_row][n_col] >= 6 && map[n_row][n_col] <= 10){
			for (int i = 0; i < holes.size(); ++i)
				if (holes[i].num == map[n_row][n_col] && (holes[i].row != n_row || holes[i].col != n_col)){
					n_row = holes[i].row;
					n_col = holes[i].col;
					break;
				}
		}
		// 종료 조건
		if ((n_row == row && n_col == col) || map[n_row][n_col] == -1) break;
	}
	return cnt;
}

int solve(){
	int max_val = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (map[i][j] == 0) // 빈공간에 대해 모두 확인한다.
				for (int dir = 0; dir < 4; ++dir)
					max_val = max(max_val, loop(i, j, dir));
			
	return max_val;
}
// 웜홀 목록 초기화
void init(){ 
	while (!holes.empty()) holes.pop_back();
}

int main(){

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d", &N);
		init();
		// 핀볼 맵 및 웜홀 목록 입력
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
		// 결과 출력
		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}