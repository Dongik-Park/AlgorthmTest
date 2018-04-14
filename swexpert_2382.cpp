#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

// 미생물 군집 정보
struct BioInfo{
	int dir;
	int row;
	int col;
	int cnt;
	bool flag;
};

int N, M, K; // 행,열의 수, 격리 시간, 미생물 군집 수
int map[101][101];
int dx[5] = { -1, 0, 1, 0 }; // 상 : 0, 좌 : 1, 하 : 2, 우 : 3
int dy[5] = { 0, -1, 0, 1 }; // 상 : 0, 좌 : 1, 하 : 2, 우 : 3
BioInfo bios[1001]; // 미생물 군집 배열

// 미생물의 수가 0이어 사라지는 경우 확인
void vanishCheck(){
	for (int i = 0; i < K; ++i)
		if (bios[i].cnt == 0)
			bios[i].flag = false;
}
// 미생물이 합쳐지는 행, 열인지 체크
void combineCheck(){
	int cur_row, cur_col;
	// 동일한 미생물의 index를 담을 벡터
	vector<int> temp;
	for (int i = 0; i < K; ++i)
		if (bios[i].flag){
			while (!temp.empty())
				temp.pop_back();
			temp.push_back(i);
			cur_row = bios[i].row;
			cur_col = bios[i].col;
			for (int j = i + 1; j < K; ++j){
				// 살아있는 미생물 && 미생물 행과 열이 같을 경우 벡터에 추가
				if (bios[j].flag && bios[j].row == cur_row && bios[j].col == cur_col)
					temp.push_back(j);
			}
			// 동일 위치에 미생물이 2개 이상일 경우
			if (temp.size() > 1){
				// 기준 0번방
				int maxCnt = bios[temp[0]].cnt;
				int targetIndex = 0;
				// 가장 큰 값을 찾는다 + 동시에 가장 큰 값의 index를 찾는다.
				for (int k = 1; k < temp.size(); ++k){
					if (bios[temp[k]].cnt > maxCnt){
						maxCnt = bios[temp[k]].cnt;
						targetIndex = k;
					}
				}
				// 찾은 최대 미생물 수 개체만 남기고 나머지는 비활성화 시킨다.
				int sum = 0;
				for (int k = 0; k < temp.size(); ++k){
					sum += bios[temp[k]].cnt;
					// 최대 미생물 아닐 경우 
					if (k != targetIndex)
						bios[temp[k]].flag = false;
				}
				// 미생물의 수는 더하고 나머지는 그대로
				bios[temp[targetIndex]].cnt = sum;
			}
		}
}
int solve(){

	// 맵 초기화
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			map[i][j] = 0;

	// 벽 표기 
	for (int i = 0; i < N; ++i){
		map[i][0] = 1;
		map[0][i] = 1;
		map[N - 1 - i][N - 1] = 1;
		map[N - 1][N - 1 - i] = 1;
	}

	// 1초 부터 M초 까지 반복
	int nrow, ncol;
	for (int i = 1; i <= M; ++i){
		// 살아있는 미생물 만큼 반복
		for (int j = 0; j < K; ++j){
			if (bios[j].flag){
				// 이동할 행, 열 갱신
				nrow = bios[j].row + dx[bios[j].dir];
				ncol = bios[j].col + dy[bios[j].dir];
				bios[j].row = nrow;
				bios[j].col = ncol;
				// 이동한 곳이 벽인 경우
				if (map[nrow][ncol] == 1){
					// 미생물 수 갱신
					bios[j].cnt = (int)(bios[j].cnt / 2);
					// 방향 갱신
					bios[j].dir = (bios[j].dir + 2) % 4;
				}
			}
		}
		// 1초마다 사라지는 미생물 검사
		vanishCheck();
		// 1초마다 합쳐지는 미생물 검사
		combineCheck();
	}
	// 결과 반환
	int sum = 0;
	for (int i = 0; i < K; ++i){
		if (bios[i].flag)
			sum += bios[i].cnt;
	}
	return sum;
}
int main(){
	int T, test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case){

		// ------ 입력 시작 ------
		scanf("%d %d %d", &N, &M, &K);
		int row, col, cnt, dir;
		for (int i = 0; i < K; ++i){
			scanf("%d %d %d %d", &row, &col, &cnt, &dir);
			// 입력 dir ( 문제 : 상 : 1, 하 : 2, 좌 : 3, 우 : 4) -> 개발자 : 상 : 0, 좌 : 1, 하 : 2, 우 : 3 로 변경)
			if (dir == 2)
				dir = 3;
			else if (dir == 3)
				dir = 2;
			BioInfo bio;
			bio.row = row;
			bio.col = col;
			bio.cnt = cnt;
			bio.dir = dir - 1;
			bio.flag = true;
			bios[i] = bio;
		}
		// ------ 입력 종료 ------

		// ------ 결과 출력 ------
		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}