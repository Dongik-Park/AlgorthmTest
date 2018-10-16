#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#define MAX_N 28
#define SHAPE 4
using namespace std;

int N, K;
int cir_que[MAX_N];
vector<string> cases;

int solve(const string str){

	while (!cases.empty()) cases.pop_back();
	
	int cnt = 0;
	while (cnt < N / SHAPE){
		// refresh standard (turn)
		int index = (N - cnt) % N;
		// make cases
		for (int i = 0; i < N; i += N / SHAPE){
			string temp;
			for (int j = 0; j < N / SHAPE; ++j){
				temp += str[index];
				index = (index + 1) % N;
			}
			// checking possible
			bool flag = true;
			for (int j = 0; j < cases.size(); ++j)
				if (cases[j].compare(temp) == 0) {
					flag = false;
					break;
				}
			if (flag) cases.push_back(temp);
		}
		++cnt;
	}
	// make hex to dec
	vector<int> values;
	for (int i = 0; i < cases.size(); ++i){
		int val1 = 0;
		int val2 = 0;
		for (int j = 0; j < cases[i].size(); ++j){
			if (cases[i][j] >= 'A') val2 += cases[i][j] - 'A' + 10;
			else val2 += cases[i][j] - '0';
			val2 = val2 * pow(16, N / SHAPE - 1 - j);
			val1 += val2;
			val2 = 0;
		}
		values.push_back(val1);
	}
	// sort by desc
	sort(values.begin(), values.end(), greater<int>());
	// return k value
	return values[K - 1];
}

int main(){

	int T, test_case;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case){
		cin >> N >> K;

		string str;
		cin >> str;

		cout << '#' << test_case << ' ' << solve(str) << endl;
	}

	return 0;
}