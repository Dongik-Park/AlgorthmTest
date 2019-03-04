#include<iostream>
#define MAX_N 20
using namespace std;

int map[MAX_N][MAX_N];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

struct Shark {
	int r;
	int c;
	int t;
};
Shark s;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if(map[i][j] == 9){
				s.r = i;
				s.c = j;
				s.t = 0;
				map[i][j] = 0;
			}
		}

	int f_size = 2;
	int eat_cnt = 0;
	Shark ss[MAX_N * MAX_N];

	bool find_next = true;
	while (find_next) {
		find_next = false;
		// queue 생성 및 현재 물고기 위치 정보를 push
		int front, rear;
		front = rear = 0;
		ss[rear++] = s;
		bool visited[MAX_N][MAX_N] = { false, };
		visited[s.r][s.c] = true;
		// 후보군 물고기 setting
		Shark candi;
		candi.r = MAX_N;
		candi.c = MAX_N;
		candi.t = -1;
		// 이동 가능한 후보를 찾는다.
		while (front != rear) {
			Shark cur = ss[front++];
			// 후보를 찾았을 경우 종료
			if (candi.t != -1 && candi.t < cur.t)
				break;
			// 먹을 수 있는 물고기일 경우
			if (map[cur.r][cur.c] > 0 && map[cur.r][cur.c] < f_size) {
				find_next = true; // 갱신 확인
				if (cur.r < candi.r || (cur.r == candi.r && cur.c < candi.c)) { // 위쪽 우선 => 왼쪽 우선
					candi = cur;
				}
			}
			// 상하좌우를 검색하여 이동 가능할 경우 queue에 추가
			for (int dir = 0; dir < 4; ++dir) {
				int nr = cur.r + dx[dir];
				int nc = cur.c + dy[dir];
				if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || map[nr][nc] > f_size)
					continue;
				// queue에 이동가능한 상어 정보 추가
				Shark n;
				n.r = nr; n.c = nc; n.t = cur.t + 1;
				ss[rear++] = n;
				visited[nr][nc] = true;
			}
		}
		// 후보군이 갱신되었을 경우
		if (find_next) {
			s = candi;
			map[s.r][s.c] = 0;
			++eat_cnt;
			if (eat_cnt == f_size) {
				++f_size;
				eat_cnt = 0;
			}
		}
	}

	cout << s.t;


	return 0;
}