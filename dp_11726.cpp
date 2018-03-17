#include<cstdio>
#include<algorithm>
using namespace std;
int arr[1010] = { 1, 1 };
int main(){
	int num;
	scanf("%d", &num);
	for (int i = 2; i <= num; ++i)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	printf("%d", arr[num]);
	return 0;
}