#include<iostream>
#include<queue>
#define MAX_N 50
using namespace std;
int N, M, r, c, d;
int map[MAX_N][MAX_N];
int dir[MAX_N][MAX_N];
// �ϵ����� ( ������� )
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int solve(){
	queue<pair<int, int> > que;
	que.push(make_pair(r, c));
	dir[r][c] = d;
	map[r][c] = 2;

	while (!que.empty()){
		pair<int, int> cur = que.front(); que.pop();
		
		// ���ʺ��� ����
		bool isPushed = false;
		for (int i = 0; i < 4; ++i){
			int n_dir = (dir[cur.first][cur.second] + 3 - i) % 4; // ���ʹ���
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
		// ������������ �������� ���Ͽ��� ���
		if (!isPushed){
			int back_dir = (dir[cur.first][cur.second] + 2) % 4; // ��ĭ ����
			int nx = cur.first + dx[back_dir];
			int ny = cur.second + dy[back_dir];
			if (nx > 0 && nx < N - 1 && ny > 0 && ny < M - 1 && map[nx][ny] != 1){ // ���� ������ ���� �ƴ� ��� ��� ����
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