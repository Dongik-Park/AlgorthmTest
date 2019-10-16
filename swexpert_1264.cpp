#include <iostream>
#define MAX_LEN 505
using namespace std;

int N, dp[MAX_LEN][MAX_LEN];
char X[MAX_LEN], Y[MAX_LEN];

int main() {
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		//init
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				dp[i][j] = 0;

		// data input
		scanf("%d %s %s", &N, X + 1, Y + 1);

		// solve
		int ans = 0;
		for (int i = 1; i <= N; i++) 
		{
			for (int j = 1; j <= N; j++) 
			{
				if (X[i] == Y[j]) 
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else 
				{
					dp[i][j] = dp[i - 1][j] < dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j]; 
				}
				ans = ans < dp[i][j] ? dp[i][j] : ans;
			}
		}
		
		// data output
		printf("#%d %.2lf\n", tc, 100.0 * ans / N);
	}
	return 0;
}
