#include<iostream>
#define MAX_N 1000
using namespace std;

int N;
int arr[MAX_N];
int val[MAX_N];

int max(int a, int b) {
	return a > b ? a : b;
}

int solve() {
	val[0] = 1;

	for (int i = 1; i < N; ++i) {
		int max_val = 0;

		// // 0 ~ 현재 index까지 중 작은것들에 대해 최대 갯수를 가지고 있는 index의 값을 찾는다. -> Dynamic programming
		for (int j = 0; j < i; ++j)
			if (arr[j] < arr[i] && val[j] > max_val)
				max_val = val[j];

		// 최대값에 현재 index를 포함한 것을 넣는다.
		val[i] = max_val + 1;
	}
	int result = 0;

	for (int i = 0; i < N; ++i)
		result = max(result, val[i]);

	return result;
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;

		for (int i = 0; i < N; ++i)
			cin >> arr[i]; 

		cout << '#' << test_case << ' ' << solve() << endl;
	}
}