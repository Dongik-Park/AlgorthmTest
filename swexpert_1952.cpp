#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cost_day;
int cost_month;
int cost_t_month;
int cost_year;
int schedule[13];
vector<int> costList;

int dfs(int curMonth){
	if (curMonth > 12){
		int sum = 0;
		for (int i = 0; i < costList.size(); ++i)
			sum += costList[i];
		return sum;
	}
	int val = numeric_limits<int>::max();

	// 해당 달을 1일 구매로 사는 경우
	costList.push_back(schedule[curMonth] * cost_day);
	val = min(val, dfs(curMonth + 1));
	costList.pop_back();

	// 해당 달을 1달 구매로 사는 경우
	costList.push_back(cost_month);
	val = min(val, dfs(curMonth + 1));
	costList.pop_back();

	// 해당 달을 3달 구매로 사는 경우
	costList.push_back(cost_t_month);
	val = min(val, dfs(curMonth + 3));
	costList.pop_back();

	return val;
}

int solve(){
	int val = numeric_limits<int>::max();
	val = min(cost_year, dfs(1));
	return val;
}

int main(){

	int T, test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case){

		// ------ 입력 시작 ------
		scanf("%d %d %d %d", &cost_day, &cost_month, &cost_t_month, &cost_year);
		for (int i = 1; i <= 12; ++i)
			scanf("%d", &schedule[i]);
		
		// ------ 입력 종료 ------

		// ------ 결과 출력 ------
		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}