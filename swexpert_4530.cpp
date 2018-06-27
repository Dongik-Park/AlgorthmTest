#include<cstdio>
using namespace std;

int strlen(const char *s)
{
	const char *eos = s;
	while (*eos++);
	return (int)(eos - s - 1);
}
long long max(long long a, long long b){
	return a > b ? a : b;
}
long long min(long long a, long long b){
	return a > b ? b : a;
}
long long solve(char * A){
	long long temp = 1, return_val = 0;
	// 양수일 경우
	if (A[0] != '-'){
		// 차상위 숫자까지 반복
		for (int i = 0; i < strlen(A) - 1; ++i)
			temp *= 9;

		if (temp != 1){
			// 마지막 숫자 계산
			for (int i = 0; i < strlen(A); ++i){
				int cur_val = A[i] - '0';
				if (cur_val > 3)
					return_val += (cur_val - 1) * temp;
				else
					return_val += cur_val * temp;
				// 각 자리수 * (각 자리수 - 1만큼 9를 곱한 값)
				temp /= 9;
			}
		}
		else{
			if (A[0] - '0' > 3)
				return_val = A[0] - '0' - 1;
			else
				return_val = A[0] - '0';
		}
	}
	// 음수일 경우
	else{
		// 차상위 숫자까지 반복
		for (int i = 1; i < strlen(A) - 1; ++i)
			temp *= 9;

		if (temp != 1){
			// 마지막 숫자 계산
			for (int i = 1; i < strlen(A); ++i){
				int cur_val = A[i] - '0';
				if (cur_val > 3)
					return_val += (cur_val - 1) * temp;
				else
					return_val += cur_val * temp;
				// 각 자리수 * (각 자리수 - 1만큼 9를 곱한 값)
				temp /= 9;
			}
		}
		else{
			if (A[1] - '0' > 3)
				return_val = A[1] - '0' - 1;
			else
				return_val = A[1] - '0';
		}
		// 음수
		return_val *= -1;
	}
	return return_val;
}
long long result(char * A, char * B){
	long long a_val = solve(A);
	long long b_val = solve(B);
	// 지하 -> 지상 이동해야할 경우
	if ((a_val < 0 && b_val >0) || (a_val > 0 && b_val < 0 ))
		return max(a_val, b_val) - min(a_val, b_val) - 1;
	return max(a_val, b_val) - min(a_val, b_val);
}
int main(){
	int N, test_case;
	scanf("%d", &N);

	char A[14];
	char B[14];
	for (test_case = 1; test_case <= N; ++test_case){
		scanf("%s %s", A, B);
		printf("#%d %lld\n", test_case, result(A, B));
	}

	return 0;
}