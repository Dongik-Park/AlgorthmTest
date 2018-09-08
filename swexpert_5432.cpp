#include<cstdio>
using namespace std;

int left[50001];
char str[100001];

int strlen(char * str){
	for (int i = 0; i < 100001; ++i){
		if (str[i] == NULL){
			return i;
		}
	}
	return -1;
}

int solve(char * str, int size){

	int left_top = -1;
	int laser_len = -1;

	int sum = 0;

	for (int i = 0; i < size; ++i){
		// is left 
		if (str[i] == '('){
			++left_top;
			left[left_top] = i;
		}
		// is right
		else{
			// left pop
			int temp_left = left[left_top];
			left[left_top] = NULL;
			--left_top;

			// ������ ���� ��� ������ �߰�
			if (temp_left == i - 1){
				// n + 1���� �ɰ����Ƿ�
				sum += left_top + 1;
			}
			// ������ ���� �ƴ� ���(�������� �ƴ� ���) count up
			else{
				++sum;
			}
		}
	}

	return sum;
}
int main(){
	int N, test_case;
	
	scanf("%d", &N);

	for (test_case = 1; test_case <= N; ++test_case){
		scanf("%s", str);
		printf("#%d %d\n", test_case, solve(str, strlen(str)));
	}

	return 0;
}