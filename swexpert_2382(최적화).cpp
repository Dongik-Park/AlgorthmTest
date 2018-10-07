#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX_N 100
using namespace std;

struct Microbe{
	int row;
	int col;
	int cnt;
	int dir;
	bool active;
};

int N, M, K; // 셀의 개수, 격리 시간, 미생물 군집 수
int dx[4] = { -1, 0, 1, 0 }; // 상좌하우
int dy[4] = { 0, -1, 0, 1 };
int map[MAX_N][MAX_N];
vector<Microbe> list;

// 약품 안에 존재하는지 확인
bool inRange(int row, int col){
	if (row > 0 && row < N - 1 && col > 0 && col < N - 1)
		return true;
	return false;
}

int solve(){

	// 1. 방향대로 이동시키고 정보 갱신한다.
	// 2. 약품에 닿았는지 확인한다. 
	//     -> 닿았을 경우 : 군집수 / 2
	//	   -> 0일 경우 군집 삭제	
	//	   -> 이동방향 갱신
	// 3. map에 count를 증가시킨다.
	// 4. 중복되는 구간(map의 count가 2이상)이 있는지 확인한다. 
	//	   -> 중복될 경우 : 1. 해당 좌표의 미생물들 중 군집수가 가장 많은 군집 찾는다.
	//	   ->			    2. 가장 많은 군집으로 군집수를 합치고 나머지는 삭제

	while (M-- != 0){
		for (int i = 0; i < list.size(); ++i){
			if (!list[i].active)
				continue;
			// 1. 방향대로 이동시키고 정보 갱신한다.
			int n_row = list[i].row + dx[list[i].dir];
			int n_col = list[i].col + dy[list[i].dir];
			list[i].row = n_row;
			list[i].col = n_col;
			// 2. 약품에 닿았을 경우
			if (!inRange(n_row, n_col)){
				// 숫자 1/2
				list[i].cnt = list[i].cnt / 2;
				// 0이될 경우 비활성화
				if (list[i].cnt == 0){
					list[i].active = false;
					continue;
				}
				// 방향 반대 갱신
				list[i].dir = (list[i].dir + 2) % 4;
			}
			// 3. map count 증가
			++map[n_row][n_col];
		}
		// 4. 중복되는 구간이 있는지 확인한다. ( 중복될 경우 수 합치고 이동방향 많은 쪽으로 )
		for (int i = 0; i < list.size(); ++i){
			if (!list[i].active) continue;
			int row = list[i].row;
			int col = list[i].col;
			// 2개 이상의 미생물이 겹치는 경우
			if (map[row][col] > 1){
				vector<int> temp;
				int max_index = i;
				temp.push_back(i);
				// 가장 군집수가 많은 미생물의 index를 찾는다.
				for (int j = i + 1; j < list.size(); ++j){
					if (!list[j].active) continue;
					if (row == list[j].row && col == list[j].col){
						temp.push_back(j);
						if (list[max_index].cnt < list[j].cnt)
							max_index = j;
					}
				}
				// 해당 index에 군집수를 추가하고 나머지는 비활성화
				for (int j = 0; j < temp.size(); ++j)
					if (temp[j] != max_index){
						list[max_index].cnt += list[temp[j]].cnt;
						list[temp[j]].active = false;
					}
			}
			// map count 초기화
			map[row][col] = 0;
		}
	}
	// 살아있는 미생물 군집 개수 총합 반환
	int sum = 0;
	for (int i = 0; i < list.size(); ++i)
		if (list[i].active)
			sum += list[i].cnt;
	return sum;
}

int main(){

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d %d", &N, &M, &K);
		// 미생물 리스트 초기화
		while (!list.empty()) list.pop_back();
		// 미생물 입력
		for (int i = 0; i < K; ++i){
			Microbe microbe;
			// 상하좌우 1234
			scanf("%d %d %d %d", &microbe.row, &microbe.col, &microbe.cnt, &microbe.dir);
			// 상하좌우 0123
			--microbe.dir;
			// 상하좌우 0213
			if (microbe.dir == 1)      microbe.dir = 2;
			else if (microbe.dir == 2) microbe.dir = 1;
			microbe.active = true;
			list.push_back(microbe);
		}

		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}