#include<cstdio>
#include<algorithm>
using namespace std;
int ary[100001] = { 0, };
int dp_cases(int num){
	int ret = numeric_limits<int>::min(), pSum = 0;
	for (int i = 0; i < num; ++i){
		pSum = max(pSum, 0) + ary[i];
		ret = max(pSum, ret);
	}
	return ret;
}
int main(){
	int num, result = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; ++i)
		scanf("%d", &ary[i]);
	printf("%d", dp_cases(num));
	return 0;
}