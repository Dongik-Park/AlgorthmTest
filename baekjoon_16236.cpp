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
		// queue ���� �� ���� ����� ��ġ ������ push
		int front, rear;
		front = rear = 0;
		ss[rear++] = s;
		bool visited[MAX_N][MAX_N] = { false, };
		visited[s.r][s.c] = true;
		// �ĺ��� ����� setting
		Shark candi;
		candi.r = MAX_N;
		candi.c = MAX_N;
		candi.t = -1;
		// �̵� ������ �ĺ��� ã�´�.
		while (front != rear) {
			Shark cur = ss[front++];
			// �ĺ��� ã���� ��� ����
			if (candi.t != -1 && candi.t < cur.t)
				break;
			// ���� �� �ִ� ������� ���
			if (map[cur.r][cur.c] > 0 && map[cur.r][cur.c] < f_size) {
				find_next = true; // ���� Ȯ��
				if (cur.r < candi.r || (cur.r == candi.r && cur.c < candi.c)) { // ���� �켱 => ���� �켱
					candi = cur;
				}
			}
			// �����¿츦 �˻��Ͽ� �̵� ������ ��� queue�� �߰�
			for (int dir = 0; dir < 4; ++dir) {
				int nr = cur.r + dx[dir];
				int nc = cur.c + dy[dir];
				if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || map[nr][nc] > f_size)
					continue;
				// queue�� �̵������� ��� ���� �߰�
				Shark n;
				n.r = nr; n.c = nc; n.t = cur.t + 1;
				ss[rear++] = n;
				visited[nr][nc] = true;
			}
		}
		// �ĺ����� ���ŵǾ��� ���
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