#include<iostream>
#define MAX_N 51
using namespace std;

int N, L;
char str[MAX_N];

int strlen(char *str) {
	int cnt = 0;
	while (str[cnt] != '\0') 
		++cnt;
	
	return cnt;
}

int solve(int idx, int cal, int score) {
	int result = 0;

	// 1과 0이 바뀌는 경우에 1을 더한다.
	if (str[0] - '0' == 1) result++;
	for (int i = 1; i < strlen(str); i++) {
		if (str[i - 1] == str[i])
			continue;
		else
			result++;
	}

	return result;
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> str;
		
		cout << '#' << test_case << ' ' << solve(0,0,0) << endl;
	}
}