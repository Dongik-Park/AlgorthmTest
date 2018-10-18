#include<iostream>
#include<algorithm>
#define MAX_N 11
#define PLUS 0
#define MINUS 1
#define MULTI 2
#define DIVI 3
using namespace std;

int arr[MAX_N];
int N;
int oper[MAX_N - 1];
int size;
pair<int,int> solve(){
	int max_val = numeric_limits<int>::min();
	int min_val = numeric_limits<int>::max();
	do{
		int val = arr[0];
		for (int i = 1; i < N; ++i){
			switch (oper[i - 1])
			{
			case PLUS: val = val + arr[i]; break;
			case MINUS:val = val - arr[i]; break;
			case MULTI:val = val * arr[i]; break;
			case DIVI: val = val / arr[i]; break;
			}
		}
		max_val = max(max_val, val);
		min_val = min(min_val, val);
	} while (next_permutation(oper, oper + size)); // using permutation to mix order

	return make_pair(max_val, min_val);
}

int main(){

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i = 0; i < 4; ++i){
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; ++j)
			oper[size++] = i;
	}

	pair<int, int> result = solve();
	cout << result.first << "\n" << result.second<<endl;

	return 0;
}