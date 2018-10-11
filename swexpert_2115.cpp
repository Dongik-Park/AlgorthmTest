#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>    
#define MAX_N 10
using namespace std;
int N, M, C;
int sqrt_val[10];
int map[MAX_N][MAX_N];
vector<int> list;
// ����� ���
int calc(){
	int sum = 0;
	for (int i = 0; i < list.size(); ++i)
		sum += sqrt_val[list[i]];
	return sum;
}
int dfs(int row, int col, int finish, int sum){
	// �Ұ����� ����� ���
	if (sum > C)
		return 0;
	// ���� ���� ��� Ž������ ���
	if (col == finish)
		return calc();
	
	int max_val = 0;
	// ���� ������ �����ϴ� ���
	list.push_back(map[row][col]);
	max_val = max(max_val, dfs(row, col + 1, finish, sum + map[row][col]));
	// ���� ������ �������� �ʴ� ���
	list.pop_back();
	max_val = max(max_val, dfs(row, col + 1, finish, sum));
	
	return max_val;
}
int solve(){

	// M�� ����
	vector<int> result;
	for (int i = 0; i < N; ++i){
		int max_val = 0;
		for (int j = 0; j <= N - M; ++j)
			max_val = max(max_val, dfs(i, j, j + M, 0));
		result.push_back(max_val);
	}
	// �������� ����
	sort(result.begin(), result.end(), greater<int>());
	// ù��°�� �ι�°�� ū �� �� ���
	return result[0] + result[1];
}

int main(){
	
	int T;
	scanf("%d", &T);

	for (int i = 1; i < 10; ++i)
		sqrt_val[i] = i * i;

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d %d", &N, &M, &C);

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				scanf("%d", &map[i][j]);

		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}