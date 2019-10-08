#include<iostream>
using namespace std;

char str[7];	// 입력 string
char ans[7];	// 결과 string
int swapCount;  // swap 횟수
int len;		// 입력 string 길이

int strlen(char * str) {
	int cnt = 0;
	while (str[cnt++] != '\0')
		;
	return cnt - 1;
}
int strcmp(const char *s1, const char *s2) {
	int ret = 0;
	while (!(ret = *(unsigned char *)s1 - *(unsigned char *)s2) && *s2)
		++s1, ++s2;

	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;

	return ret;
}
char *strcpy(char *dst, const char *src) {
	char *cp = dst;
	while (*cp++ = *src++)
		;
	return dst;
}

void swap(char *str, int i, int j) {
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

void solve(char *str, int cnt, int offset) {
	// 종료조건 : swap 선택이 완료된 경우
	if (cnt == 0) {
		// str이 더 큰 값일 경우 갱신
		if (strcmp(str, ans) > 0) {
			strcpy(ans, str);
		}
		return;
	}

	for (int i = offset; i < len; ++i) {
		for (int j = i; j < len; ++j) {
			if (i == j || str[i] > str[j]) continue; // i의 값이 클경우
			swap(str, i, j);
			solve(str, cnt - 1, i); // i위치부터 추가 진행
			swap(str, j, i);
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		// data input
		cin >> str;
		cin >> swapCount;

		// solve
		len = strlen(str);
		strcpy(ans, "");
		solve(str, swapCount, 0);

		// data output
		cout << "#"<< test_case << " " << ans << endl;
	}
	return 0;
}


