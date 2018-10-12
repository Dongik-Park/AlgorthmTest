#include<cstdio>
#include<algorithm>
#include<vector>
#define MAX_N 20
#define MAX_LEN 40
using namespace std;

int N, M;
int map[MAX_N][MAX_N];
vector<pair<int, int> > houses;
int k_val[MAX_LEN] = { 1, 5, 13, 25, 41, 61, 85, 113, 145, 181, 221, 265, 313, 365, 421, 481, 545, 613, 685, 761, 841, 925, 1013, 1105, 1201, 1301, 1405, 1513, 1625, 1741, 1861, 1985, 2113, 2245, 2381, 2521, 2665, 2813, 2965, 3121 };
/*  
	for (int i = 1; i <= 40; i++)
		printf("%d, ", i*i + (i - 1)*(i - 1));
*/
int calc(int row, int col){
	int result = 0;
	int cnt[MAX_LEN] = {0,};

	// �� �Ÿ��� �ش��ϴ� �ε����� �Ÿ��� �����ϴ� ��Ҹ� ǥ���Ѵ�.
	for (int i = 0; i < houses.size(); ++i){
		int dist = abs(row - houses[i].first) + abs(col - houses[i].second);
		++cnt[dist];
	}
	// �� �Ÿ��� ���� ���ԵǴ� ���� ������ ǥ���Ѵ�.
	for (int i = 1; i < MAX_LEN; ++i)
		cnt[i] += cnt[i - 1];
	// ���ؿ��θ� Ȯ���ϰ� �ִ� ��� �����Ѵ�.
	for (int i = 0; i < MAX_LEN; ++i)
		if (k_val[i] <= cnt[i] * M)
			result = max(result, cnt[i]);

	return result;
}
int solve(){
	int max_val = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			max_val = max(max_val, calc(i,j));

	return max_val;
}
int main(){
	
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d", &N, &M);
		while (!houses.empty()) houses.pop_back();

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j){
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1) houses.push_back(make_pair(i, j));
			}

		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}