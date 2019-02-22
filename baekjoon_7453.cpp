#include<iostream>
#include<algorithm>
#define MAX_SIZE 4001
using namespace std;

long long AB[MAX_SIZE * MAX_SIZE], CD[MAX_SIZE * MAX_SIZE];

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);

	long A[MAX_SIZE] = { 0, };
	long B[MAX_SIZE] = { 0, };
	long C[MAX_SIZE] = { 0, };
	long D[MAX_SIZE] = { 0, };

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			AB[idx] = A[i] + B[j];
			CD[idx++] = C[i] + D[j];
		}
	}
	sort(CD, CD + N * N);    // BS로 찾을 기준 배열만 정렬.

	long long cnt = 0;
	long left = 0, right = N * N;

	for (int i = 0; i < N * N; i++) {    // AB배열의 처음부터 N*N번째까지 BS로 쌍을 찾는다.

		while (left < right) {
			long long mid = (left + right) / 2;
			if (AB[i] + CD[mid] < 0) left = mid + 1;
			else right = mid;
		}
		long lower_bound = right;
		left = 0, right = N * N;

		while (left < right) {
			long long mid = (left + right) / 2;

			if (AB[i] + CD[mid] <= 0) left = mid + 1;
			else right = mid;
		}
		long upper_bound = right;

		cnt += upper_bound - lower_bound;
		left = 0, right = N * N;
	}
	printf("%lld\n", cnt);
	return 0;
}