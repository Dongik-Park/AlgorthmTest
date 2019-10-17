#include<iostream>
using namespace std;

// N / P에 숫자들이 가까울수록 높다.
int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int N, P, mod;
		long long max = 1;
		// data input
		cin >> N >> P;

		// solve
		mod = N % P;
		for (int i = 0; i < P - mod; i++)  // N / P에 가까운 애들을 먼저 곱한다.
			max *= (N / P);
		for (int i = 0; i < mod; i++) // 나머지는 1씩늘어나는 것이 가장 큰 곱
			max *= ((N / P) + 1);

		// data output
		cout << "#" << test_case << " " << max << endl;
	}

	return 0;
}
