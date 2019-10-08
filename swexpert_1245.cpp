#include <iostream>
using namespace std;

int N;
double X[11], mass[11];

double abs(double x) {
	if (x >= 0)  return x;
	return -x;
}

double calc(double cur, int idx) {
	return mass[idx] / (abs(cur - X[idx]) * abs(cur - X[idx])); // 질량 / (위치 - x좌표)^2
}

int main() {
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		// data input
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%lf", X + i);
		}
		for (int i = 0; i < N; i++) {
			scanf("%lf", mass + i);
		}

		// data output
		printf("#%d ", tc);
		for (int i = 1; i < N; i++) { // 2개당 1개 존재
			double left  = X[i - 1] + 1e-10; // 소수점 이하 10자리
			double right = X[i] - 1e-10;
			for (int j = 0; j < 100; j++) { // binary
				double mid = (left + right) / 2; // 중간값 갱신
				double lsum, rsum;
				lsum = rsum = 0;
				for (int k = 0; k < N; k++) { // 왼쪽 합계
					if (X[k] > mid)  break;
					lsum += calc(mid, k);
				}
				for (int k = N - 1; k >= 0; k--) { // 오른쪽 합계
					if (X[k] < mid)  break;
					rsum += calc(mid, k);
				}
				if (lsum < rsum) right = mid; 
				else left = mid;
			}
			printf("%.10lf ", left);
		}
		printf("\n");
	} // end of test_case

	return 0;
}