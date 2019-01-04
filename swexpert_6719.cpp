#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
double levels[10000];

double solve(int idx, double level, int cnt) {
	double result = 0;
	for (int i = N - K; i < N; ++i) // 가장 뒤 - K번부터 가장 뒤까지의 강좌를 수강한다.
		result = (levels[i] + result) / 2;
	return result;
}

int main()
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		for (int i = 0; i < N; ++i)
			cin >> levels[i];

		// 오름차순으로 정렬한다. ( 낮은 수준부터 수강하는게 유리하다 )
		sort(levels, levels + N);

		cout << fixed;
		cout.precision(6);
		cout << "#" << test_case << " " << solve(0, 0, 0) << endl;
	}
	return 0;
}
