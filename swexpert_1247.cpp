#include<iostream>

using namespace std;

int N;				  // 고객의 수 (2≤N≤10)
int h[1][2];		  // 집좌표
int c[1][2];		  // 회사좌표
int customers[10][2]; // 고객 좌표 목록
bool visited[10];	  // 방문 여부
int ans;

int abs(const int a) {
	return a < 0 ? -a : a;
}

int min(const int a, const int b) {
	return a > b ? b : a;
}

void backtracking(int dist, int n, int prev_x, int prev_y) {
	if (n == 0) { // 모든 고객 방문
		int toHome = abs(prev_x - h[0][0]) + abs(prev_y - h[0][1]);
		ans = min(dist + toHome, ans);
		return;
	}
	if (dist > ans) { //  ans보다 크면 방문할 필요 x
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		backtracking(
			dist + abs(customers[i][0] - prev_x) + abs(customers[i][1] - prev_y),
			n - 1,
			customers[i][0],
			customers[i][1]
		);
		visited[i] = false;
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		// initialization
		ans = 100000;
		for (int i = 0; i < 10; ++i)
			visited[i] = false;

		// data input
		cin >> N;
		cin >> c[0][0] >> c[0][1] >> h[0][0] >> h[0][1];
		for (int i = 0; i < N; ++i)
			cin >> customers[i][0] >> customers[i][1];

		// solve
		backtracking(0, N, c[0][0], c[0][1]);

		// data output
		cout << "#" << tc << " " << ans << endl;

	} // end of test case 

	return 0;
}

//
//int T, N, X[12], Y[12], dp[12][1 << 12];
//
//int min(int x, int y) {
//	return (x < y ? x : y);
//}
//int calc_dist(int x, int y) {
//	int xdiff = abs(X[x] - X[y]);
//	int ydiff = abs(Y[x] - Y[y]);
//	return xdiff + ydiff;
//}
//
//int func(int cur, int visit) {
//	if (visit == ((1 << N) - 1)) {
//		return calc_dist(cur, 1);
//	}
//	int &ret = dp[cur][visit];
//	if (ret != -1)  // already visited
//		return ret;
//	ret = 1e9;
//	for (int i = 0; i < N; i++) 
//		if (!(visit & (1 << i))) 
//			ret = min(ret, func(2 + i, visit | (1 << i)) + calc_dist(cur, 2 + i));
//		
//	return ret;
//}
//
//int main() {
//	scanf("%d", &T);
//	for (int tc = 1; tc <= T; tc++) {
//		// initialization
//		for (int i = 0; i < 12; i++)
//			for (int j = 0; j < (1 << 12); j++)
//				dp[i][j] = -1;
//
//		// data input
//		scanf("%d", &N);
//		for (int i = 0; i < N + 2; i++) 
//			scanf("%d %d", X + i, Y + i);
//
//		// data output
//		printf("#%d %d\n", tc, func(0, 0));
//	}
//	return 0;
//}
