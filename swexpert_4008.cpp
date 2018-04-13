#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int N;
int oper[13];
int numArr[13];
vector<int> order;
int solve(){
	while (!order.empty()){
		order.pop_back();
	}
	for (int i = 0; i < N - 1; ++i){
		order.push_back(oper[i]);
	}
	int maxVal = numeric_limits<int>::min();
	int minVal = numeric_limits<int>::max();
	do{
		int result = numArr[0];
		for (int i = 0; i < N - 1; ++i){
			// 0 : 더하기 , 1 : 뺴기, 2 : 곱하기, 3 : 나누기
			switch (order[i]){
			case 0: result = result + numArr[i + 1]; break;
			case 1: result = result - numArr[i + 1]; break;
			case 2: result = result * numArr[i + 1]; break;
			case 3: result = result / numArr[i + 1]; break;
			}
		}
		maxVal = max(maxVal, result);
		minVal = min(minVal, result);
	} while (next_permutation(order.begin(), order.end()));

	return maxVal - minVal;
}
int main(){
	int T, test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case){
		// ------ 입력 시작 ------
		scanf("%d", &N);
		int operIndex = -1;
		for (int i = 0; i < 4; ++i){
			int cnt = 0;
			scanf("%d", &cnt);
			if (cnt != 0){
				for (int j = 0; j < cnt; ++j)
					oper[++operIndex] = i;
			}
		}
		for (int i = 0; i < N; ++i)
			scanf("%d", &numArr[i]);
		// ------ 입력 종료 ------

		// ------ 결과 출력 ------
		printf("#%d %d\n", test_case, solve());
	}
	return 0;
}