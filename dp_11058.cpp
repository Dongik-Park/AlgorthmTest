#include<cstdio>
#include<algorithm>
using namespace std;
int N;
long long ary[1010];
int main(){
	int N;
	long long cur;
	scanf("%d", &N);
	for (int i = 0; i <= 6; i++) {
		ary[i] = i;
	}
	for (int i = 7; i <= N; ++i)
		for (int j = 3; j <= i - 1; ++j){
			 cur = ary[i - j] * (j - 1); // ary[i - j]*(j - 3) + ary[i - j]*(2) <- Ctrl+A, Ctrl+C 
			 if (cur > ary[i])
				 ary[i] = cur;
		}
	printf("%d", ary[N]);
	return 0;
}