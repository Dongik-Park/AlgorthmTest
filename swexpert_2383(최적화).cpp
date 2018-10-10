#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX_N 10
#define INT_MAX 2147483647

using namespace std;

int N;
int map[MAX_N][MAX_N];
vector<pair<int, int> > men;
vector<pair<int, int> > stairs;

vector<int> first_stairs;
vector<int> second_stairs;
int min_val = INT_MAX;

int calc(){
	queue<int> first_stair;
	queue<int> second_stair;
	queue<int> first_wait;
	queue<int> second_wait;

	// 첫번째와 두번째 계단을 선택한 목록에 대해 계단 도착 시간 + 대기시간을 계산하여 추가한다.
	vector<int> f_temp;
	vector<int> s_temp;
	for (int i = 0; i < first_stairs.size(); ++i)
		f_temp.push_back(abs(men[first_stairs[i]].first - stairs[0].first) + abs(men[first_stairs[i]].second - stairs[0].second) + 1);
	for (int i = 0; i < second_stairs.size(); ++i)
		s_temp.push_back(abs(men[second_stairs[i]].first - stairs[1].first) + abs(men[second_stairs[i]].second - stairs[1].second) + 1);
	// 각 시간을 오름차순으로 정렬한다.
	sort(f_temp.begin(), f_temp.end());
	sort(s_temp.begin(), s_temp.end());

	// 마지막 인원이 계단을 모두 내려가는 시간을 기록한다.
	for (int i = 3; i < f_temp.size(); ++i)
		f_temp[i] = max(f_temp[i], f_temp[i - 3] + map[stairs[0].first][stairs[0].second]);
	for (int i = 3; i < s_temp.size(); ++i)
		s_temp[i] = max(s_temp[i], s_temp[i - 3] + map[stairs[1].first][stairs[1].second]);
	
	int time1 = 0;
	int time2 = 0;

	if (f_temp.size() > 0)
		time1 = f_temp[f_temp.size() - 1] + map[stairs[0].first][stairs[0].second];
	if (s_temp.size() > 0)
		time2 = s_temp[s_temp.size() - 1] + map[stairs[1].first][stairs[1].second];

	return max(time1, time2);
	/*
	queue<int> f_time;
	queue<int> s_time;
	for (int i = 0; i < f_temp.size(); ++i)
		f_time.push(f_temp[i]);
	for (int i = 0; i < s_temp.size(); ++i)
		s_time.push(s_temp[i]);

	int time = 0;
	while (!f_time.empty() || !s_time.empty() || !first_wait.empty() || !second_wait.empty()){
		++time;
		if (time > min_val) break;

		// 계단을 내려가는 것 중 시간이 다되었는지 확인
		while (!first_stair.empty()){
			if (first_stair.front() != time) break;
			first_stair.pop();
		}
		while (!second_stair.empty()){
			if (second_stair.front() != time) break;
			second_stair.pop();
		}

		// 계단을 내려가는 인원이 3명 미만이고 계단 대기큐가 존재하는 경우 계단 도착 시간을 계산하여 추가
		while (first_stair.size() < 3 && !first_wait.empty()){
			int fin_time = map[stairs[0].first][stairs[0].second] + time;
			first_stair.push(fin_time);
			first_wait.pop(); // 대기큐 첫원소 제거
		}
		while (second_stair.size() < 3 && !second_wait.empty()){
			int fin_time = map[stairs[1].first][stairs[1].second] + time;
			second_stair.push(fin_time);
			second_wait.pop(); // 대기큐 첫원소 제거
		}

		// 계단에 도착한 
		while (!f_time.empty()){
			if (f_time.front() == time) {
				first_wait.push(f_time.front());
				f_time.pop();
			}
			else break;
		}
		while (!s_time.empty()){
			if (s_time.front() == time) {
				second_wait.push(s_time.front());
				s_time.pop();
			}
			else break;
		}
	}
	while (!first_stair.empty()){
		time = max(time, first_stair.front()); first_stair.pop();
	}
	while (!second_stair.empty()){
		time = max(time, second_stair.front()); second_stair.pop();
	}


	return time;*/
}
// 1. 각 사람들이 1번 또는 2번 계단을 선택한다.
int solve(int index){
	if (index == men.size()){
		return calc();
	}

	first_stairs.push_back(index);
	min_val = min(min_val, solve(index + 1));
	first_stairs.pop_back();
	second_stairs.push_back(index);
	min_val = min(min_val, solve(index + 1));
	second_stairs.pop_back();

	return min_val;
}

int main(){

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d", &N);

		while (!men.empty()) men.pop_back();
		while (!stairs.empty()) stairs.pop_back();
		min_val = INT_MAX;

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j){
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1)
					men.push_back(make_pair(i, j));
				else if (map[i][j] > 1)
					stairs.push_back(make_pair(i, j));
			}

		printf("#%d %d\n", test_case, solve(0));
	}

	return 0;
}