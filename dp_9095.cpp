#include<cstdio>
#include<algorithm>
using namespace std;
int dp_cases(int num){
	if (num < 0)
		return 0;
	if (num == 0)
		return 1;
	return dp_cases(num - 1) + dp_cases(num - 2) + dp_cases(num - 3);
}
int main(){
	int num, test_case;
	scanf("%d", &num);
	for (int i = 0; i < num; ++i){
		scanf("%d", &test_case);
		printf("%d\n", dp_cases(test_case));
	}
	return 0;
}