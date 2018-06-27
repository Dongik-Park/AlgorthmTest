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
	// ����� ���
	if (A[0] != '-'){
		// ������ ���ڱ��� �ݺ�
		for (int i = 0; i < strlen(A) - 1; ++i)
			temp *= 9;

		if (temp != 1){
			// ������ ���� ���
			for (int i = 0; i < strlen(A); ++i){
				int cur_val = A[i] - '0';
				if (cur_val > 3)
					return_val += (cur_val - 1) * temp;
				else
					return_val += cur_val * temp;
				// �� �ڸ��� * (�� �ڸ��� - 1��ŭ 9�� ���� ��)
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
	// ������ ���
	else{
		// ������ ���ڱ��� �ݺ�
		for (int i = 1; i < strlen(A) - 1; ++i)
			temp *= 9;

		if (temp != 1){
			// ������ ���� ���
			for (int i = 1; i < strlen(A); ++i){
				int cur_val = A[i] - '0';
				if (cur_val > 3)
					return_val += (cur_val - 1) * temp;
				else
					return_val += cur_val * temp;
				// �� �ڸ��� * (�� �ڸ��� - 1��ŭ 9�� ���� ��)
				temp /= 9;
			}
		}
		else{
			if (A[1] - '0' > 3)
				return_val = A[1] - '0' - 1;
			else
				return_val = A[1] - '0';
		}
		// ����
		return_val *= -1;
	}
	return return_val;
}
long long result(char * A, char * B){
	long long a_val = solve(A);
	long long b_val = solve(B);
	// ���� -> ���� �̵��ؾ��� ���
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