#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int N;				// 행, 열 개수
int map[11][11];	// 맵 입력
int tempMap[11][11];// 임시 맵
int fst_row;	    // 첫번째 계단 행
int fst_col;		// 첫번째 계단 열
int snd_row;		// 두번째 계단 행
int snd_col;		// 두번째 계단 열
queue<int> firstWaitQ;  // 첫번째 계단 대기 큐
queue<int> firstMoveQ;  // 첫번째 계단 이동 큐
queue<int> secondWaitQ; // 두번째 계단 대기큐
queue<int> secondMoveQ; // 두번째 계단 이동 큐
vector<pair<int, int>> firstList;  // 첫번째 계단을 선택한 사람 목록
vector<pair<int, int>> secondList; // 두번째 계단을 선택한 사람 목록
vector<pair<int, int>> personList; // 사람 좌표 목록
int cnt_person; // 사람 수

// 초기 맵으로 복구
void recoverMap(){
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			map[i][j] = tempMap[i][j];
}
// map의 모든 1 (모든 사람)이 0인지 (계단으로 이동했는지 검사)
bool isFinished(){
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (map[i][j] == 1)
				return false;
	return true;
}
// 완전 탐색 
int dfs(int cur_person){
	int result = numeric_limits<int>::max();
	// 아직 사람 목록 끝까지 탐색 안한 경우
	if (cur_person < cnt_person){
		// 현재 사람 좌표 추출
		pair<int, int> cur = personList[cur_person];

		// 첫번째 계단 목록에 추가하고
		firstList.push_back(make_pair(cur.first, cur.second));
		// 다음 사람 돌린다.
		result = min(result, dfs(cur_person + 1));
		// 첫번째 선택한 경우 제외
		firstList.pop_back();

		// 맵 복구
		recoverMap();

		// 두번째 계단 목록에 추가하고
		secondList.push_back(make_pair(cur.first, cur.second));
		// 다음 사람 돌린다.
		result = min(result, dfs(cur_person + 1));
		// 두번째 선택한 경우 제외
		secondList.pop_back();

		// 맵 복구
		recoverMap();
	}
	// 마지막 사람까지 온 경우 지금까지 결정된 사항으로 결과 시간 계산한다.
	else{
		int cur_time = 0;
		while (!firstWaitQ.empty())
			firstWaitQ.pop();
		while (!firstMoveQ.empty())
			firstMoveQ.pop();
		while (!secondWaitQ.empty())
			secondWaitQ.pop();
		while (!secondMoveQ.empty())
			secondMoveQ.pop();
		// 모든 사람이 대기큐 또는 이동큐로 간 경우 || 각 대기큐와 이동큐가 모두 비어있을 때 까지 반복
		while (!isFinished() || !firstWaitQ.empty() || !firstMoveQ.empty() || !secondWaitQ.empty() || !secondMoveQ.empty()){
			// 변수 선언
			int cur_row, cur_col;
			// 현재 시간 증가 (1초부터시작)
			++cur_time;

			// ------------------------------------  1번 계단 선택 루틴 시작 ------------------------------------ 

			// 1번 선택한 사람 중에 현재 시간 안에 드는 사람을 1번 계단 대기 큐 추가한다.
			for (int i = 0; i < firstList.size(); ++i){
				cur_row = firstList[i].first;
				cur_col = firstList[i].second;
				if (map[cur_row][cur_col] == 1 && abs(fst_row - cur_row) + abs(fst_col - cur_col) == cur_time){
					// 큐에 들어간 시간을 기록한다.
					firstWaitQ.push(cur_time);
					// 추가되었으므로 map을 0으로 만든다.
					map[cur_row][cur_col] = 0;
				}
			}
			// 1번 계단 이동 큐에 이동 시간이 완료된 인원 있는지 찾는다.
			while (!firstMoveQ.empty()){
				int qTime = firstMoveQ.front();
				// 완료된 인원있으면 꺼낸다.
				if (cur_time == qTime)
					firstMoveQ.pop();
				else
					break;
			}
			// 1번 계단 대기 큐에 인원 중 1초 이상 기다린 사람 찾는다.
			while (!firstWaitQ.empty()){
				// 대기큐에 들어온 순서대로 진행한다.
				int qTime = firstWaitQ.front();
				// 1초 이상 기다린 경우 && 1번 계단 이동 큐가 공간이 있는지 비었는지 확인하고 삽입 
				if (cur_time - qTime >= 1 && firstMoveQ.size() < 3){
					// 이동 큐에 넣을 때에는 종료 예정 시간을 기록한다.
					firstMoveQ.push(cur_time + map[fst_row][fst_col]);
					firstWaitQ.pop();
				}
				else
					break;
			}
			// ------------------------------------  1번 계단 선택 루틴 종료 ------------------------------------ 


			// ------------------------------------  2번 계단 선택 루틴 시작 ------------------------------------ 

			// 2번 선택한 사람 중에 현재 시간 안에 드는 사람을 2번 계단 대기 큐 추가한다.
			for (int i = 0; i < secondList.size(); ++i){
				cur_row = secondList[i].first;
				cur_col = secondList[i].second;
				if (map[cur_row][cur_col] == 1 && abs(snd_row - cur_row) + abs(snd_col - cur_col) == cur_time){
					// 큐에 들어간 시간을 기록한다.
					secondWaitQ.push(cur_time);
					// 추가되었으므로 map을 0으로 만든다.
					map[cur_row][cur_col] = 0;
				}
			}
			// 2번 계단 이동 큐에 이동 시간이 완료된 인원 있는지 찾는다.
			while (!secondMoveQ.empty()){
				int qTime = secondMoveQ.front();
				// 완료된 인원있으면 꺼낸다.
				if (cur_time == qTime)
					secondMoveQ.pop();
				else
					break;
			}
			// 2번 계단 대기 큐에 인원 중 1초 이상 기다린 사람 찾는다.
			while (!secondWaitQ.empty()){
				// 대기큐에 들어온 순서대로 진행한다.
				int qTime = secondWaitQ.front();
				// 1초 이상 기다린 경우 && 2번 계단 이동 큐가 공간이 있는지 비었는지 확인하고 삽입 
				if (cur_time - qTime >= 1 && secondMoveQ.size() < 3){
					// 이동 큐에 넣을 때에는 종료 예정 시간을 기록한다.
					secondMoveQ.push(cur_time + map[snd_row][snd_col]);
					secondWaitQ.pop();
				}
				else
					break;
			}
			// ------------------------------------  2번 계단 선택 루틴 종료 ------------------------------------ 
		}
		// 해당 탐색 결과 저장
		result = cur_time;
	}
	// 최소 결과 반환
	return result;
}
int solve(){
	int time;
	// 사람 좌표 리스트 생성한다.
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (map[i][j] == 1)
				personList.push_back(make_pair(i, j));
	// 사람 수 갱신 ( 1 이상 )
	cnt_person = personList.size();
	// 완전 탐색 결과 저장
	time = dfs(0);
	// 결과 반환
	return time;
}
int main(){

	int T, test_case;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){

		// ------ 입력 시작 ------
		scanf("%d", &N);
		fst_row = 0;
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j){
				scanf("%d", &map[i][j]);
				if (map[i][j] > 1){
					if (fst_row == 0){
						fst_row = i;
						fst_col = j;
					}
					else{
						snd_row = i;
						snd_col = j;
					}
				}
				tempMap[i][j] = map[i][j];
			}
		// ------ 입력 종료 ------

		// --- 변수 초기화 시작 ---
		while (!firstWaitQ.empty())
			firstWaitQ.pop();
		while (!firstMoveQ.empty())
			firstMoveQ.pop();
		while (!secondWaitQ.empty())
			secondWaitQ.pop();
		while (!secondMoveQ.empty())
			secondMoveQ.pop();
		while (!firstList.empty())
			firstList.pop_back();
		while (!secondList.empty())
			secondList.pop_back();
		while (!personList.empty())
			personList.pop_back();
		// --- 변수 초기화 종료 ---

		// ------ 결과 출력 ------
		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}