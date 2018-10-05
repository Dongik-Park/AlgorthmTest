#include <cstdio>
#include <queue>
#define MAX_LEN 50
using namespace std;

int N, M, R, C, L;
int map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
// �� ���� �̵� �� ���� ����
int in_up[4] = { 1, 2, 5, 6 };
// �� ���� �̵� �� ���� ����
int out_up[4] = { 1, 2, 4, 7 };
// �� ���� �̵� �� ���� ����
int in_side[4] = { 1, 3, 4, 5 };
// �� ���� �̵� �� ���� ����
int out_side[4] = { 1, 3, 6, 7 };
bool inRange(int row, int col){
	if (row > -1 && row < N && col > -1 && col < M)
		return true;
	return false;
}
// �̵��������� Ȯ���Ѵ�.
bool moveable(int row, int col, int n_row, int n_col, int dir){
	bool flag = false;
	bool flag2 = false;
	switch (dir)
	{
	case 0: // ���� ��ġ���� ������ �̵��� ���
		for (int i = 0; i < 4; ++i){
			if (map[row][col] == out_up[i]) flag = true;
			if (map[n_row][n_col] == in_up[i])flag2 = true;
		}break;
	case 1: // ���� ��ġ���� �Ϸ� �̵��� ���
		for (int i = 0; i < 4; ++i){
			if (map[row][col] == in_up[i]) flag = true;
			if (map[n_row][n_col] == out_up[i])flag2 = true;
		}break;
	case 2: // ���� ��ġ���� �·� �̵��� ���
		for (int i = 0; i < 4; ++i){
			if (map[row][col] == out_side[i]) flag = true;
			if (map[n_row][n_col] == in_side[i])flag2 = true;
		}break;
	case 3: // ���� ��ġ���� ��� �̵��� ���
		for (int i = 0; i < 4; ++i){
			if (map[row][col] == in_side[i]) flag = true;
			if (map[n_row][n_col] == out_side[i])flag2 = true;
		}break;
	}
	if (flag && flag2)
		return true;
	return false;
}
// ���� ������ ��ǥ�� ������ ����Ѵ�.
int calc(){
	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (visited[i][j])
				++cnt;
	return cnt;
}
// 1�� ������ ������ ��ǥ�� �߰��Ѵ�.
int solve(){
	queue<pair<int, int> > que;
	que.push(make_pair(R, C));
	visited[R][C] = true;
	// L ��ŭ �ݺ�
	while (--L != 0){
		// ���� ť �����ŭ �ݺ��Ѵ�.
		int size = que.size();
		for (int i = 0; i < size; ++i){
			pair<int, int> cur = que.front(); que.pop();
			int row = cur.first;
			int col = cur.second;
			// �����¿쿡 ���� �˻� �� ť�� �߰��Ѵ�.
			for (int j = 0; j < 4; ++j){
				int n_row = row + dx[j];
				int n_col = col + dy[j];
				// ���� �ȿ� ���ϰ� 0�� �ƴϸ鼭 �湮���� �ʾҰ� �̵������� ��� ť�� �߰�
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
// �湮 �迭�� �� �ʱ�ȭ
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