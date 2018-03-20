#include<cstdio>
#include<algorithm>
using namespace std;
long long ary[91];
int main(){
	int num;
	scanf("%d", &num);
	ary[0] = 0;
	ary[1] = 1;
	for (int i = 2; i <= num; ++i)
		ary[i] = ary[i - 1] + ary[i - 2];
	printf("%lld", ary[num]);
	return 0;
}