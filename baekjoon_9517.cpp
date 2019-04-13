#include<iostream>
#define BOMB 210
using namespace std;

int main(){
	int target, time;
	int N;
	cin >> target >> N;
	time = 0;
	
	for (int i = 0; i < N; ++i){
		int curTime;
		char result;
		cin >> curTime >> result;
		// 시간초증가
		time += curTime;
		// 대답하는데 걸린 시간이 3분30초 이상일 경우
		if (time >= BOMB){
			break;
		}
		// 문제 통과일 경우
		if (result == 'T'){
			// 왼쪽 사람에게 전달
			++target;
			if (target == 9)
				target = 1;
		}
	}
	cout << target;
	return 0;
}