#include<iostream>
#include<vector>
#include<queue>
#define MAX_N 8
using namespace std;
int N, M;
int map[MAX_N][MAX_N];
int temp_map[MAX_N][MAX_N];
bool isChecked[MAX_N][MAX_N];
vector<pair<int, int> > virus;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool inRange(int row, int col){
	if (row >= 0 && row < N && col >= 0 && col < M) return true;
	return false;
}
int max(int a, int b){
	return a > b ? a : b;
}
int calc(){
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			temp_map[i][j] = map[i][j]; // 맵 복사

	queue<pair<int, int>> que;
	for (int i = 0; i < virus.size(); ++i)
		que.push(virus[i]); // 바이러스 목록 추가

	while (!que.empty()){ // bfs
		pair<int, int> cur = que.front(); que.pop();
		for (int i = 0; i < 4; ++i){
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (inRange(nx, ny) && temp_map[nx][ny] == 0) {
				temp_map[nx][ny] = 2;
				que.push(make_pair(nx, ny));
			}
		}
	}

	int cnt = 0; // counting
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (temp_map[i][j] == 0) ++cnt;
	return cnt;
}
int dfs(int cnt){
	if (cnt == 3) return calc();

	int max_val = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (map[i][j] == 0 && !isChecked[i][j]){
				isChecked[i][j] = true; // 다음 검사에서 중복하지 않도록 검사 대상 제외
				map[i][j] = 1;
				max_val = max(max_val, dfs(cnt + 1));
				isChecked[i][j] = false; // 다음 검사 대상 포함
				map[i][j] = 0;
			}

	return max_val;
}
int solve(int cnt){
	int max_val = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (map[i][j] == 0){
				isChecked[i][j] = true; // 이 좌표의 모든 경우를 검사하므로 검사 대상 제외
				map[i][j] = 1;
				max_val = max(max_val, dfs(cnt + 1));
				map[i][j] = 0;
			}
		
	return max_val;
}
int main(){

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j){
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
			isChecked[i][j] = false;
		}

	cout << solve(0) << endl;

	return 0;
}