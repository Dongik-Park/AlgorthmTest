#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N;
int area[21][21];
string str;

void solve() {
	queue<int> qu;
	if (str.compare("left") == 0) {//哭率
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (area[i][j]) {
					qu.push(area[i][j]);
					area[i][j] = 0;
				}
			}
			int idx = 0;
			while (!qu.empty()) {
				if (area[i][idx] == 0) {
					area[i][idx] = qu.front();
				}
				else {
					if (area[i][idx] == qu.front()) {
						area[i][idx++] *= 2;
					}
					else {
						area[i][++idx] = qu.front();
					}
				}
				qu.pop();
			}
		}
	}
	else if (str.compare("right") == 0) {//坷弗率
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (area[i][j]) {
					qu.push(area[i][j]);
					area[i][j] = 0;
				}
			}
			int idx = N - 1;
			while (!qu.empty()) {
				if (area[i][idx] == 0) {
					area[i][idx] = qu.front();
				}
				else {
					if (area[i][idx] == qu.front()) {
						area[i][idx--] *= 2;
					}
					else {
						area[i][--idx] = qu.front();
					}
				}
				qu.pop();
			}
		}
	}
	else if (str.compare("up") == 0) {//困率
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (area[i][j]) {
					qu.push(area[i][j]);
					area[i][j] = 0;
				}
			}
			int idx = 0;
			while (!qu.empty()) {
				if (area[idx][j] == 0) {
					area[idx][j] = qu.front();
				}
				else {
					if (area[idx][j] == qu.front()) {
						area[idx++][j] *= 2;
					}
					else {
						area[++idx][j] = qu.front();
					}
				}
				qu.pop();
			}
		}
	}
	else {//关率
		for (int j = 0; j < N; j++) {
			for (int i = N - 1; i >= 0; i--) {
				if (area[i][j]) {
					qu.push(area[i][j]);
					area[i][j] = 0;
				}
			}
			int idx = N - 1;
			while (!qu.empty()) {
				if (area[idx][j] == 0) {
					area[idx][j] = qu.front();
				}
				else {
					if (area[idx][j] == qu.front()) {
						area[idx--][j] *= 2;
					}
					else {
						area[--idx][j] = qu.front();
					}
				}
				qu.pop();
			}
		}
	}
}

int main() {
	fastio();
	int TC;
	cin >> TC;
	for (int T = 1; T <= TC; T++) {
		cin >> N;
		cin >> str;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> area[i][j];
			}
		}
		solve();
		cout << '#' << T << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << area[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}