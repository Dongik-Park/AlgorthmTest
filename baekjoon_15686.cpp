#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 50
#define INT_MAX 2147483647

using namespace std;

int N, M;
int map[MAX_N + 1][MAX_N + 1];
vector<pair<int, int> > homes;
vector<pair<int, int> > chickens;

vector<int> selected;
int calc(){
	// 선택된 치킨집에 대해 계산한다.
	int sum = 0;

	for (int i = 0; i < homes.size(); ++i){
		int min_val = INT_MAX;
		for (int j = 0; j < selected.size(); ++j){
			min_val = min(min_val,
				abs(homes[i].first - chickens[selected[j]].first)
				+ abs(homes[i].second - chickens[selected[j]].second));
		}
		sum += min_val;
	}
	return sum;
}

int dfs(int index){
	int min_val = INT_MAX;

	if (selected.size() == M)
		return calc();

	if (index >= chickens.size())
		return min_val;

	// 현재 좌표 포함
	selected.push_back(index);
	min_val = min(min_val, dfs(index + 1));
	selected.pop_back();
	min_val = min(min_val, dfs(index + 1));

	return min_val;
}

int solve(){

	return dfs(0);
}

int main(){

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j){
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				homes.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				chickens.push_back(make_pair(i, j));
		}

	printf("%d", solve());

	return 0;
}