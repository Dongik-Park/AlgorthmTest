#include<iostream>
using namespace std;

// N / P�� ���ڵ��� �������� ����.
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
		for (int i = 0; i < P - mod; i++)  // N / P�� ����� �ֵ��� ���� ���Ѵ�.
			max *= (N / P);
		for (int i = 0; i < mod; i++) // �������� 1���þ�� ���� ���� ū ��
			max *= ((N / P) + 1);

		// data output
		cout << "#" << test_case << " " << max << endl;
	}

	return 0;
}
