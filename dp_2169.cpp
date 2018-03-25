#include <cstdio>
#include<algorithm>
using namespace std;
int col, row;
int ary[1001][1001];
int dp[1001][1001];
int right[1001];
int dp_cases()
{
	int i, j;
	// first row 
	for (i = 1; i <= row; i++)    
		dp[1][i] = dp[1][i - 1] + ary[1][i];

	for (i = 2; i <= col; i++) {
		dp[i][1] = dp[i - 1][1] + ary[i][1];
		// up & left
		for (j = 2; j <= row; j++) 
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + ary[i][j];
		right[row] = dp[i - 1][row] + ary[i][row];
		// up & right 
		for (j = row - 1; j > 0; j--) 
			right[j] = max(dp[i - 1][j], right[j + 1]) + ary[i][j];
		// find max between (up & left) and (up & right)
		for (j = 1; j <= row; j++) 
			dp[i][j] = max(dp[i][j], right[j]);
	}
	return dp[col][row];
}

int main()
{
	int i, j;
	scanf("%d %d", &col, &row);
	for (i = 1; i <= col; i++)    
		for (j = 1; j <= row; j++) 
			scanf("%d", &ary[i][j]);
	printf("%d\n", dp_cases());
	return 0;
}