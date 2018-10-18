#include<iostream>
#include<algorithm>
#define MAX_N 20
using namespace std;

int map[MAX_N][MAX_N];
int N;
int t1[MAX_N];
int t2[MAX_N];
int t1_size;
int t2_size;
int ans = numeric_limits<int>::max();
int cnt;
void dfs(int index){ // N명을 t1, t2팀으로 나눈다.
	if (!ans) return; // 최소 경우 찾을 시 종료
	if (index == N){ // 모든 팀 배분 완료
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < N / 2 - 1; ++i)
			for (int j = i + 1; j < N / 2; ++j){
				sum1 += map[t1[i]][t1[j]] + map[t1[j]][t1[i]];
				sum2 += map[t2[i]][t2[j]] + map[t2[j]][t2[i]];
			}
		ans = min(ans, abs(sum1 - sum2));
		return;
	}
	if (t1_size < N / 2){ // 1팀 배분
		t1[t1_size++] = index;
		dfs(index + 1);
		--t1_size;
	}
	if (t2_size < N / 2){ // 2팀 배분
		t2[t2_size++] = index;
		dfs(index + 1);
		--t2_size;
	}
}
int main(){

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> map[i][j];

	dfs(0);

	cout << ans << endl;

	return 0;
}