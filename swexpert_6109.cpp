#include<iostream>
#define MAX_N 20
using namespace std;

int N;
int map[MAX_N][MAX_N]; // Ÿ�� 
int temp[MAX_N]; // �� ���� ������ �ӽ�Ÿ��
char s_dir[10]; // ���� �Է�
char dirs[4][10] = { "up", "down", "left", "right" };

int strlen(char * str) {
	int cnt = 0;
	while (str[cnt] != '\0') ++cnt;
	return cnt;
}

int strcmp(char *s1, char *s2) {
	for (int i = 0; i < strlen(s1); ++i) {
		if (s1[i] > s2[i]) return 1;
		else if (s2[i] > s1[i]) return -1;
	}
	return 0;
}

void sort(int * temp, int cnt) {
	int temp2[MAX_N];
	int idx = 0;
	for (int i = 0; i < cnt; ++i)
		if ( i + 1 < N && temp[i] == temp[i + 1]) {
			temp2[idx++] = temp[i] + temp[i + 1];
			++i;
		}
		else
			temp2[idx++] = temp[i];
	// ���ķδ� 0������ 
	for (int i = idx; i < N; ++i)
		temp2[i] = 0;
	for (int i = 0; i < N; ++i)
		temp[i] = temp2[i];
}

void move(int dir) {

	// �����¿�
	switch (dir) {
	case 0: 
		for (int i = 0; i < N; ++i) {
			int cnt = 0;
			for (int j = 0; j < N; ++j)
				if (map[j][i] > 0 ) {
					temp[cnt++] = map[j][i];
				}
			// temp�� �����Ѵ�.
			sort(temp, cnt);
			// ���� �˻� ���� �����Ѵ�.
			for (int j = 0; j < N; ++j) {
				map[j][i] = temp[j];
				temp[j] = 0;
			}
		}
		break;
	case 1:
		for (int i = 0; i < N; ++i) {
			int cnt = 0;
			for (int j = N - 1; j >= 0; --j)
				if (map[j][i] > 0) {
					temp[cnt++] = map[j][i];
				}
			// temp�� �����Ѵ�.
			sort(temp, cnt);
			// ���� �˻� ���� �����Ѵ�.
			for (int j = 0; j < N; ++j){
				map[N - 1 - j][i] = temp[j];
				temp[j] = 0;
			}
		}
		break;
	case 2:
		for (int i = 0; i < N; ++i) {
			int cnt = 0;
			for (int j = 0; j < N; ++j)
				if (map[i][j] > 0) {
					temp[cnt++] = map[i][j];
				}
			// temp�� �����Ѵ�.
			sort(temp, cnt);
			// ���� �˻� ���� �����Ѵ�.
			for (int j = 0; j < N; ++j){
				map[i][j] = temp[j];
				temp[j] = 0;
			}
		}
		break;
	case 3:
		for (int i = 0; i < N; ++i) {
			int cnt = 0;
			for (int j = N - 1; j >= 0; --j)
				if (map[i][j] > 0) {
					temp[cnt++] = map[i][j];
				}
			// temp�� �����Ѵ�.
			sort(temp, cnt);
			// ���� �˻� ���� �����Ѵ�.
			for (int j = 0; j < N; ++j){
				map[i][N - 1 - j] = temp[j];
				temp[j] = 0;
			}
		}
		break;
	}
}

void solve() {
	// ���� ����
	int dir = 0;
	for (int i = 0; i < 4; ++i) {
		int temp = strcmp(s_dir, dirs[i]);
		if (temp == 0) {
			dir = i;
			break;
		}
	}
	// �̵�
	move(dir);
	// ��� ���
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << map[i][j] << ' ';
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> N >> s_dir;

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> map[i][j];

		cout << '#' << test_case << endl;
		solve();
	}

	return 0;
}