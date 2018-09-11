#include<cstdio>

using namespace std;

int arr[50001];

int solve(int N){

	scanf("%d", &arr[0]);

	int l_cnt = 1;
	int r_cnt = 0;

	int sum = 0;

	for (int i = 1; i < N; ++i){
		scanf("%d", arr + i);
		// 현재 값이 더 클 경우
		if (*(arr + i) > *(arr + (i - 1))){
			if (r_cnt != 0){
				sum += r_cnt * l_cnt;
				l_cnt = 1;
			}
			r_cnt = 0;
			++l_cnt;
		}
		// 현재 값이 더 작을 경우
		else{
			if (r_cnt == 0 && l_cnt > 0){
				--l_cnt;
			}
			++r_cnt;
		}
	} 
	// 마지막 열 체크하여 더한다.
	if (r_cnt != 0){
		sum += r_cnt * l_cnt;
	}

	return sum;
}
int main(){
	int num, test_case;

	scanf("%d", &num);

	for (test_case = 1; test_case <= num; ++test_case){
		int N;
		scanf("%d", &N);
		printf("#%d %d\n", test_case, solve(N));
	}

	return 0;
}