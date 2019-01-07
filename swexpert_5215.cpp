#include<iostream>
#define MAX_N 20
using namespace std;

int N, L;
int arr[MAX_N][2];

int max(int a, int b) {
	return a > b ? a : b;
}

int solve(int idx, int cal, int score) {
	if (idx < N) {
		if (cal + arr[idx][1] <= L)
			return max(solve(idx + 1, cal + arr[idx][1], score + arr[idx][0]), solve(idx + 1, cal, score));
		else
			return solve(idx + 1, cal, score);
	}
	// ���� �Ĵ��� �����ϴ� ���� ���ϴ� ���		
	return score;
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> L;

		for (int i = 0; i < N; ++i)
			cin >> arr[i][0] >> arr[i][1]; // ���� ���� �� Į�θ� �Է�

		cout << '#' << test_case << ' ' << solve(0, 0, 0) << endl;
	}
}