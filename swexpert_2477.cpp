#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int N, M, K, A, B; // 접수 창구, 정비 창구, 방문 고객 수, 분실 고객 접수 창구 번호, 분실 고객 정비 창구 번호
int N_map[10];     // 접수 창구 담당자의 처리 가능 시간
int M_map[10];     // 정비 창구 담당자의 처리 가능 시간
int tk[1001];	   // 고객들의 정비소 도착 시간
int N_used[10];    // 현재 접수 창구를 이용중인 고객 번호
int M_used[10];    // 현재 정비 창구를 이용 중인 고객 번호
int N_visited_time[10]; // 다음 고객을 받을 수 있는 시간 ( 현재시간 + 창구 담당자의 처리 가능 시간 )
int M_visited_time[10]; // 다음 고객을 받을 수 있는 시간 ( 현재시간 + 창구 담당자의 처리 가능 시간 )
int N_num[1001];   // k번 고객이 부여받은 접수 창구 번호
int M_num[1001];   // k번 고객이 부여받은 정비 창구 번호
int cur_time;	   // 현재 시간
queue<int> firstQ; //접수 창구 대기 큐
queue<int> secondQ;//정비 창구 대기 큐

// 모든 고객들이 접수와 정비 창구를 방문했는지
bool isFinished(){
	int i;
	for (i = 1; i <= K; ++i)
		if (N_num[i] == 0)
			return false;
	for (i = 1; i <= K; ++i)
		if (M_num[i] == 0)
			return false;
	return true;
}
// 정비 창구에 고객 배정
int insertToM(int customerNum){
	int i;
	for (i = 1; i <= M; ++i)
		if (!M_used[i]){
			// 정비창구에 고객 배정
			M_used[i] = customerNum;
			// 고객 방문시간 + 처리시간 저장
			M_visited_time[i] = cur_time + M_map[i];
			// 고객이 방문한 정비창구 번호 저장
			M_num[customerNum] = i;
			break;
		}
	if (i == M + 1)
		return -1;
	return i;
}
// 현재 시간 기준 정비 창구 이용 완료 고객 확인
void checkM(){
	for (int i = 1; i <= M; ++i)
		// 현재 시간에 정비창구 처리 완료된 고객있으면
		if (cur_time == M_visited_time[i]){
			// 해당 접수 창구 고객 처리 시간 초기화
			M_visited_time[i] = -1;
			// 해당 접수 창구 고객 번호 초기화
			M_used[i] = 0;
		}
}
// 현재 시간 기준 접수 창구 이용 완료 고객 확인
void checkN(){
	// 접수 창구 번호가 작은 순서대로 들어간다.
	for (int i = 1; i <= N; ++i)
		// 현재 시간에 접수창구 처리 완료된 고객있으면
		if (cur_time == N_visited_time[i]){
			// 정비창구 대기큐에 삽입하고
			secondQ.push(N_used[i]);
			// 해당 접수 창구 고객 처리 시간 초기화
			N_visited_time[i] = -1;
			// 해당 접수 창구 고객 번호 초기화
			N_used[i] = 0;
		}
}
// 접수 창구에 고객 배정
int insertToN(int customerNum){
	int i;
	for (i = 1; i <= N; ++i)
		if (!N_used[i]){
			// 접수창구에 고객 배정
			N_used[i] = customerNum;
			// 고객의 방문 시간 + 처리시간 저장
			N_visited_time[i] = cur_time + N_map[i];
			// 고객이 방문한 접수창구 번호 저장
			N_num[customerNum] = i;
			break;
		}
	if (i == N + 1)
		return -1;
	return i;
}
int solve(){
	int i;
	while (!isFinished()){
		//고객 온 순서대로 접수 창구 큐에 대기
		for (i = 1; i <= K; ++i)
			if (cur_time == tk[i])
				firstQ.push(i);
			else if (cur_time < tk[i])
				break;
		//현재시간 기준에 처리된 고객을 정비창구로 배분 및 접수 창구 비우기
		checkN();
		// 대기하고 있는 고객있으면
		if (!firstQ.empty()){
			int customerNum = firstQ.front();
			// 접수창구에 접수 가능할 경우 계속 배정
			while (insertToN(customerNum) != -1){
				// 배정되었으면 큐에서 제거
				firstQ.pop();
				if (!firstQ.empty())
					customerNum = firstQ.front();
				else
					break;
			}
		}

		//현재시간 기준에 처리된 고객의 정비 창구 비우기
		checkM();
		// 대기하고 있는 고객있으면
		if (!secondQ.empty()){
			int customerNum = secondQ.front();
			// 정비창구에 접수 가능할 경우 계속 배정
			while (insertToM(customerNum) != -1){
				// 할당되었으면 큐에서 제거
				secondQ.pop();
				if (!secondQ.empty())
					customerNum = secondQ.front();
				else
					break;
			}
		}

		// 현재 시간 증가
		++cur_time;
	}
	// 접수, 정비 창구 번호 확인 및 결과 반환
	int sum = 0;
	for (int i = 1; i <= K; ++i)
		if (N_num[i] == A && M_num[i] == B)
			sum += i;
	if (sum == 0)
		return -1;
	return sum;
}
int main(){
	int T, test_case;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		int i;
		// ------ 입력 시작 ------
		for (i = 1; i <= N; ++i)
			scanf("%d", &N_map[i]);
		for (i = 1; i <= M; ++i)
			scanf("%d", &M_map[i]);
		for (i = 1; i <= K; ++i)
			scanf("%d", &tk[i]);
		// ------ 입력 종료 ------

		// --- 변수 초기화 시작 ---
		for (int j = 1; j <= N; ++j)
			N_visited_time[j] = -1;
		for (int j = 1; j <= M; ++j)
			M_visited_time[j] = -1;
		for (int j = 1; j <= N; ++j)
			N_used[j] = 0;
		for (int j = 1; j <= M; ++j)
			M_used[j] = 0;
		for (int j = 1; j <= K; ++j)
			N_num[j] = 0;
		for (int j = 1; j <= K; ++j)
			M_num[j] = 0;
		cur_time = 0;
		while (!firstQ.empty())
			firstQ.pop();
		while (!secondQ.empty())
			secondQ.pop();
		// --- 변수 초기화 종료 ---

		// ------ 결과 출력 ------
		printf("#%d %d\n", test_case, solve());
	}
	return 0;
}