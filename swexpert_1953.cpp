#include <cstdio>
#include <queue>
#define MAX_LEN 50
using namespace std;

int N, M, R, C, L;
int map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
// 하 방향 이동 상 방향 진입
int in_up[4] = { 1, 2, 5, 6 };
// 상 방향 이동 하 방향 진입
int out_up[4] = { 1, 2, 4, 7 };
// 우 방향 이동 좌 방향 진입
int in_side[4] = { 1, 3, 4, 5 };
// 상 방향 이동 우 방향 진입
int out_side[4] = { 1, 3, 6, 7 };
bool inRange(int row, int col){
	if (row > -1 && row < N && col > -1 && col < M)
		return true;
	return false;
}
// 이동가능한지 확인한다.
bool moveable(int row, int col, int n_row, int n_col, int dir){
	bool flag = false;
	bool flag2 = false;
	switch (dir)
	{
	case 0: // 현재 위치에서 상으로 이동할 경우
		for (int i = 0; i < 4; ++i){
			if (map[row][col] == out_up[i]) flag = true;
			if (map[n_row][n_col] == in_up[i])flag2 = true;
		}break;
	case 1: // 현재 위치에서 하로 이동할 경우
		for (int i = 0; i < 4; ++i){
			if (map[row][col] == in_up[i]) flag = true;
			if (map[n_row][n_col] == out_up[i])flag2 = true;
		}break;
	case 2: // 현재 위치에서 좌로 이동할 경우
		for (int i = 0; i < 4; ++i){
			if (map[row][col] == out_side[i]) flag = true;
			if (map[n_row][n_col] == in_side[i])flag2 = true;
		}break;
	case 3: // 현재 위치에서 우로 이동할 경우
		for (int i = 0; i < 4; ++i){
			if (map[row][col] == in_side[i]) flag = true;
			if (map[n_row][n_col] == out_side[i])flag2 = true;
		}break;
	}
	if (flag && flag2)
		return true;
	return false;
}
// 접근 가능한 좌표의 개수를 계산한다.
int calc(){
	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (visited[i][j])
				++cnt;
	return cnt;
}
// 1초 단위로 가능한 좌표를 추가한다.
int solve(){
	queue<pair<int, int> > que;
	que.push(make_pair(R, C));
	visited[R][C] = true;
	// L 만큼 반복
	while (--L != 0){
		// 현재 큐 사이즈만큼 반복한다.
		int size = que.size();
		for (int i = 0; i < size; ++i){
			pair<int, int> cur = que.front(); que.pop();
			int row = cur.first;
			int col = cur.second;
			// 상하좌우에 대해 검사 후 큐에 추가한다.
			for (int j = 0; j < 4; ++j){
				int n_row = row + dx[j];
				int n_col = col + dy[j];
				// 범위 안에 속하고 0이 아니면서 방문하지 않았고 이동가능할 경우 큐에 추가
				if (inRange(n_row, n_col) && 
					map[n_row][n_col] != 0 && 
					!visited[n_row][n_col] && 
					moveable(row, col, n_row, n_col, j)){
					que.push(make_pair(n_row, n_col));
					visited[n_row][n_col] = true;
				}
			}
		}
	}

	return calc();
}
// 방문 배열과 맵 초기화
void init(){
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			visited[i][j] = false;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			map[i][j] = 0;
}
int main(){

	int T;
	scanf("%d", &T);
	
	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		init();

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				scanf("%d", &map[i][j]);

		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}