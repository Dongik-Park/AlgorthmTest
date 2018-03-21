#include<cstdio>
#include<algorithm>
using namespace std;
int ary[1001][1001];
int row, col;
//int dp_cases(int _row, int _col){
//	if (row == _row && col == _col)
//		return ary[row][col];
//	if (_row > row || _col > col)
//		return 0;
//	return max(max(dp_cases(_row+1,_col),dp_cases(_row, _col+1)),dp_cases(_row+1,_col+1))+ ary[_row][_col];
//}
int main(){
	scanf("%d %d", &row, &col);
	for (int i = 1; i <= row; ++i)
		for (int j = 1; j <= col; ++j)
			scanf("%d", &ary[i][j]);

	// By for loop
	for (int i = 1; i <= row; ++i)
		for (int j = 1; j <= col; ++j)
			ary[i][j] = max(max(ary[i - 1][j], ary[i][j - 1]), ary[i - 1][j - 1]) + ary[i][j];
	printf("%d", ary[row][col]);

	// By recursive
	//printf("%d", dp_cases(1, 1));
	return 0;
}
