#include<cstdio>
#include<algorithm>

using namespace std;
int map[1001];
int row;
int solve(){
	int sum = 0; 
	for (int i = 3; i <= row - 2; ++i){
		if (map[i - 2] < map[i] && map[i - 1] < map[i] && map[i + 1] < map[i] && map[i + 2] < map[i]){
			int min_val = map[i];
			min_val = min(min_val, map[i] - map[i - 2]);
			min_val = min(min_val, map[i] - map[i - 1]);
			min_val = min(min_val, map[i] - map[i + 1]);
			min_val = min(min_val, map[i] - map[i + 2]);
			sum += min_val;
		}
	}
	return sum;
}
int main(){
	for (int i = 0; i < 10; ++i){
		scanf("%d", &row);
		for (int j = 1; j <= row; ++j)
			scanf("%d", &map[j]);
		printf("#%d %d\n", i + 1, solve());
	}

	return 0;
}