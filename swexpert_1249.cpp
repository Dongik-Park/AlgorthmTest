#include<iostream>
#include<queue>
#define MAX_N 100
using namespace std;

int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;
int dist[MAX_N][MAX_N];

void bfs() {
	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N&&ny < N) {
				if (!visited[nx][ny] || dist[nx][ny] > dist[x][y] + map[nx][ny]) {
					dist[nx][ny] = dist[x][y] + map[nx][ny];
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// data input
		cin >> N;
		char line[MAX_N];
		for (int i = 0; i < N; i++) {
			cin >> line;
			for (int j = 0; j < N; j++) {
				map[i][j] = line[j] - '0';
				dist[i][j] = visited[i][j] = false;
			}
		}

		// solve
		bfs();

		// data output
		cout << "#" << tc << " " << dist[N - 1][N - 1] << endl;
	}
}