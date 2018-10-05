#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 8
using namespace std;

int N, K;
int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int result;

bool inRange(int row, int col){
	if (row >= 0 && row < N && col >= 0 && col < N)
		return true;
	return false;
}
void dfs(int row, int col, int height, int len, int used){
	// 결과 갱신
	result = max(len, result);

	for (int j = 0; j < 4; ++j){
		int n_row = row + dx[j];
		int n_col = col + dy[j];
		if (!inRange(n_row, n_col) || visited[n_row][n_col])
			continue;
		if (map[n_row][n_col] < height){
			visited[n_row][n_col] = true;
			dfs(n_row, n_col, map[n_row][n_col], len + 1, used);
			visited[n_row][n_col] = false;
		}
		else{
			if (used == 0 && map[n_row][n_col] - K < height){
				visited[n_row][n_col] = true;
				dfs(n_row, n_col, height - 1, len + 1, 1);
				visited[n_row][n_col] = false;
			}
		}
	}
}

int main(){

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d", &N, &K);
		int max_val = 0;
		result = 0;

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j){
				scanf("%d", &map[i][j]);
				max_val = max(max_val, map[i][j]);
				visited[i][j] = false;
			}

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (max_val == map[i][j]){
					visited[i][j] = true;
					dfs(i, j, map[i][j], 1, 0);
					visited[i][j] = false;
				}

		printf("#%d %d\n", test_case, result);
	}

	return 0;
}