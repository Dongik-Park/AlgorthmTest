#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX_LEN 100
using namespace std;
int N;
int col, row, d, g;
bool map[MAX_LEN + 1][MAX_LEN + 1];
// �� �� �� �� : �ݽð���� ��
int drow[4] = { -1, 0, 1, 0 };
int dcol[4] = { 0, -1, 0, 1 };
int min_col = MAX_LEN; // �ּ� �� ��ǥ
int min_row = MAX_LEN; // �ּ� �� ��ǥ
int max_col = 0; // �ִ� �� ��ǥ
int max_row = 0; // �ִ� �� ��ǥ
// �ּ� �� �ִ� ��ǥ�� �������� �������� 4���� �� ���
int calc(){
	int cnt = 0;
	for (int i = min_row; i < max_row; ++i)
		for (int j = min_col; j < max_col; ++j)
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				++cnt;
	return cnt;
}
// �ּ� �� �ִ� ��ǥ ����
void checkMinAndMax(){
	min_col = min(min_col, col);
	min_row = min(min_row, row);
	max_col = max(max_col, col);
	max_row = max(max_row, row);
}
void solve(){
	// 0���� ǥ��
	vector<int> dir_vec;
	dir_vec.push_back(d);
	map[row][col] = true;
	checkMinAndMax();
	row += drow[d];
	col += dcol[d];
	map[row][col] = true;
	checkMinAndMax();
	// ���� �� ��ŭ �ݺ�
	while (--g > -1){
		int size = dir_vec.size();
		// ���� �̵� ����� �������� ��ǥ ���� �� ���Ϳ� �߰��� ������.
		for (int i = size - 1; i > -1; --i){
			int n_dir = (dir_vec[i] + 1) % 4;
			row += drow[n_dir];
			col += dcol[n_dir];
			map[row][col] = true;
			dir_vec.push_back(n_dir);
			checkMinAndMax();
		}
	}
	return;
}

int main(){

	scanf("%d", &N);

	for (int i = 0; i < N; ++i){
		scanf("%d %d %d %d", &col, &row, &d, &g); 
		d = (d + 3) % 4;
		solve();
	}

	printf("%d", calc());

	return 0;
}