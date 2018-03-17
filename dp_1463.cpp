#include <cstdio>
#include <algorithm>
using namespace std;

int dp_cases(int i) {
	if (i < 2)
		return 0;
	else
		return min(dp_cases(i / 2) + i % 2, dp_cases(i / 3) + i % 3) + 1;
}

int main() {
	int num;
	scanf("%d", &num);
	printf("%d", dp_cases(num));
	return 0;
}