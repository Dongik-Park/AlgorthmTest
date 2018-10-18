#include<iostream>
#include<queue>
#define MAX_N 50
using namespace std;
int N, M, r, c, d;
int map[MAX_N][MAX_N];
int dir[MAX_N][MAX_N];
// 북동하좌 ( 상우하좌 )
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int solve(){
	queue<pair<int, int> > que;
	que.push(make_pair(r, c));
	dir[r][c] = d;
	map[r][c] = 2;

	while (!que.empty()){
		pair<int, int> cur = que.front(); que.pop();
		
		// 왼쪽부터 삽입
		bool isPushed = false;
		for (int i = 0; i < 4; ++i){
			int n_dir = (dir[cur.first][cur.second] + 3 - i) % 4; // 왼쪽방향
			int nx = cur.first + dx[n_dir];
			int ny = cur.second + dy[n_dir];
			if (nx > 0 && nx < N - 1 && ny > 0 && ny < M - 1 && map[nx][ny] == 0){
				map[nx][ny] = 2;
				dir[nx][ny] = n_dir;
				que.push(make_pair(nx, ny));
				isPushed = true;
				break;
			}
		}
		// 다음방향으로 진행하지 못하였을 경우
		if (!isPushed){
			int back_dir = (dir[cur.first][cur.second] + 2) % 4; // 한칸 후진
			int nx = cur.first + dx[back_dir];
			int ny = cur.second + dy[back_dir];
			if (nx > 0 && nx < N - 1 && ny > 0 && ny < M - 1 && map[nx][ny] != 1){ // 뒤쪽 방향이 벽이 아닌 경우 계속 진행
				map[nx][ny] = 2;
				dir[nx][ny] = dir[cur.first][cur.second];
				que.push(make_pair(nx, ny));
				continue;
			}
			else break;
		}
	}
	// counting
	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (map[i][j] == 2) ++cnt;
	return cnt;
}
int main(){

	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> map[i][j];

	cout << solve() << endl;
	return 0;
}