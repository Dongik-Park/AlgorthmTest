#include <stdio.h>
#define MAX_MONTH 12

int day, month, quarter, year;
int schedule[MAX_MONTH + 1];

int min(int a, int b){
	return a > b ? b : a;
}

int solve(){
	int cost[MAX_MONTH + 1];
	cost[0] = 0;
	for (int i = 1; i <= MAX_MONTH; ++i){
		// Dynamic Programming을 활용하여 이전달까지의 최소값 + 현재 달의 경우의 수 중 최소값으로 갱신해나간다.
		cost[i] = min(cost[i - 1] + day * schedule[i],
					  cost[i - 1] + month);
		// 3개월 이상의 경우 갱신된 최소값과 3개월 전의 비용 + 분기 비용과 비교한다.
		if (i >= 3)
			cost[i] = min(cost[i], cost[i - 3] + quarter);
	}
	// 1년 이용권과 비교 결과를 반환
	return min(year, cost[MAX_MONTH]);
}
int main(){
	
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d %d %d", &day, &month, &quarter, &year);

		for (int i = 1; i <= MAX_MONTH; ++i)
			scanf("%d", &schedule[i]);

		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}