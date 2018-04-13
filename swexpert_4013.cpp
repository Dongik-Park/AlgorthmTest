#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

// ------ 함수 헤더 시작 ------
void fourthTurn(int, int);
void thirdTurn(int, int);
void secondTurn(int, int);
void firstTurn(int, int);
// ------ 함수 헤더 종료 ------

int K;		   // 움직일 자석 개수
int first[8];  // 1번 자석 정보
int second[8]; // 2번 자석 정보
int third[8];  // 3번 자석 정보
int fourth[8]; // 4번 자석 정보
int fst_stand; // 1번 기준
int snd_stand; // 2번 기준
int tth_stand; // 3번 기준
int fth_stand; // 4번 기준
queue<pair<int,int>> dirQue; // 자석 번호, 방향 ( 시계 : 1, 반시계 -1 )

// 4번 회전 루틴
void fourthTurn(int dir, int prevTurn){
	// 4번 - 3번과 인접한 index
	int ftNearIndex = (fth_stand + 6) % 8;
	// 3번 - 4번과 인접한 index
	int tfNearIndex = (tth_stand + 2) % 8;

	// 현재 4번을 돌리고 있는 중이면 
	if (prevTurn == 4){
		// 4와 같은 극이 아닐 경우만 3번을 돌려준다.( 반대 방향으로 회전 )
		if (third[tfNearIndex] != fourth[ftNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			thirdTurn(nextDir, 4);
		}
		// 시계방향 일 경우
		if (dir == 1)
			fth_stand = (fth_stand + 7) % 8;
		// 반시계방향 일 경우
		else
			fth_stand = (fth_stand + 1) % 8;
	}
	// 현재 4번 돌리는 중이 아니라면
	else{
		// 3번과 인접한 자성의 극이 다른 경우 회전한다.
		if (third[tfNearIndex] != fourth[ftNearIndex]){
			// 시계방향 일 경우
			if (dir == 1)
				fth_stand = (fth_stand + 7) % 8;
			// 반시계방향 일 경우
			else
				fth_stand = (fth_stand + 1) % 8;
		}
		else
			return;
	}
}
// 3번 회전 루틴
void thirdTurn(int dir, int prevTurn){
	// 2번 - 3번과 인접한 index
	int stNearIndex = (snd_stand + 2) % 8;
	// 3번 - 2번과 인접한 index
	int tsNearIndex = (tth_stand + 6) % 8;
	// 3번 - 4번과 인접한 index
	int tfNearIndex = (tth_stand + 2) % 8;
	// 4번 - 3번과 인접한 index
	int ftNearIndex = (fth_stand + 6) % 8;

	// 현재 3번을 돌리고 있는 중이면 
	if (prevTurn == 3){
		// 3와 같은 극이 아닐 경우만 2번을 돌려준다.( 반대 방향으로 회전 )
		if (second[stNearIndex] != third[tsNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			secondTurn(nextDir, 3);
		}
		// 3와 같은 극이 아닐 경우만 4번을 돌려준다.( 반대 방향으로 회전 )
		if (fourth[ftNearIndex] != third[tfNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			fourthTurn(nextDir, 3);
		}
		// 시계방향 일 경우
		if (dir == 1)
			tth_stand = (tth_stand + 7) % 8;
		// 반시계방향 일 경우
		else
			tth_stand = (tth_stand + 1) % 8;
	}
	// 현재 2번으로 부터 왔을 경우
	else if (prevTurn == 2){
		// 2번과 인접한 자성의 극이 다른 경우 회전한다.
		if (second[stNearIndex] != third[tsNearIndex]){
			// 시계방향 일 경우
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			// 반시계방향 일 경우
			else
				nextDir = 1;
			// 4번으로 이동하여 확인한다.
			fourthTurn(nextDir, 3);

			// 3번 기준 갱신
			if (dir == 1)
				tth_stand = (tth_stand + 7) % 8;
			// 반시계방향 일 경우
			else
				tth_stand = (tth_stand + 1) % 8;
		}
		else
			return;
	}
	// 현재 4번으로 부터 왔을 경우
	else if (prevTurn == 4){
		// 3번과 인접한 자성의 극이 다른 경우 회전한다.
		if (fourth[ftNearIndex] != third[tfNearIndex]){
			int nextDir;
			// 시계방향 일 경우
			if (dir == 1)
				nextDir = -1;
			// 반시계방향 일 경우
			else
				nextDir = 1;

			// 2번으로 이동하여 확인한다.
			secondTurn(nextDir, 3);

			// 3번 기준 갱신
			if (dir == 1)
				tth_stand = (tth_stand + 7) % 8;
			// 반시계방향 일 경우
			else
				tth_stand = (tth_stand + 1) % 8;
		}
		else
			return;
	}
}
// 2번 회전 루틴
void secondTurn(int dir, int prevTurn){
	// 1번 - 2번과 인접한 index
	int fsNearIndex = (fst_stand + 2) % 8;
	// 2번 - 1번과 인접한 index
	int sfNearIndex = (snd_stand + 6) % 8;
	// 2번 3번과 인접한 index
	int stNearIndex = (snd_stand + 2) % 8;
	// 3번 - 2번과 인접한 index
	int tsNearIndex = (tth_stand + 6) % 8;

	// 현재 2번을 돌리고 있는 중이면 
	if (prevTurn == 2){
		// 2와 같은 극이 아닐 경우만 1번을 돌려준다.( 반대 방향으로 회전 )
		if (first[fsNearIndex] != second[sfNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			firstTurn(nextDir, 2);
		}
		// 2와 같은 극이 아닐 경우만 3번을 돌려준다.( 반대 방향으로 회전 )
		if (third[tsNearIndex] != second[stNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			thirdTurn(nextDir, 2);
		}
		// 시계방향 일 경우
		if (dir == 1)
			snd_stand = (snd_stand + 7) % 8;
		// 반시계방향 일 경우
		else
			snd_stand = (snd_stand + 1) % 8;
	}
	// 현재 1번으로 부터 왔을 경우
	else if (prevTurn == 1){
		// 2번과 인접한 자성의 극이 다른 경우 회전한다.
		if (first[fsNearIndex] != second[sfNearIndex]){
			// 시계방향 일 경우
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			// 반시계방향 일 경우
			else
				nextDir = 1;

			// 3번으로 이동하여 확인한다.
			thirdTurn(nextDir, 2);

			// 2번 기준 회전
			if (dir == 1)
				snd_stand = (snd_stand + 7) % 8;
			// 반시계방향 일 경우
			else
				snd_stand = (snd_stand + 1) % 8;
		}
		else
			return;
	}
	else if (prevTurn == 3){
		// 3번과 인접한 자성의 극이 다른 경우 회전한다.
		if (third[tsNearIndex] != second[stNearIndex]){
			// 시계방향 일 경우
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			// 반시계방향 일 경우
			else
				nextDir = 1;

			// 3번으로 이동하여 확인한다.
			firstTurn(nextDir, 2);

			// 2번 기준 회전
			if (dir == 1)
				snd_stand = (snd_stand + 7) % 8;
			// 반시계방향 일 경우
			else
				snd_stand = (snd_stand + 1) % 8;
		}
		else
			return;
	}
}
// 1번 회전 루틴
void firstTurn(int dir, int prevTurn){
	// 1번 - 2번과 인접한 index
	int fNearIndex = (fst_stand + 2) % 8;
	// 2번 - 1번과 인접한 index
	int sNearIndex = (snd_stand + 6) % 8;

	// 현재 1번을 돌리고 있는 중이면 
	if (prevTurn == 1){
		// 2와 같은 극이 아닐 경우만 2번을 돌려준다.( 반대 방향으로 회전 )
		if (first[fNearIndex] != second[sNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			secondTurn(nextDir, 1);
		}
		// 시계방향 일 경우
		if (dir == 1)
			fst_stand = (fst_stand + 7) % 8;
		// 반시계방향 일 경우
		else
			fst_stand = (fst_stand + 1) % 8;
	}
	// 현재 1번 돌리는 중이 아니라면
	else{
		// 2번과 인접한 자성의 극이 다른 경우 회전한다.
		if (first[fNearIndex] != second[sNearIndex]){
			// 시계방향 일 경우
			if (dir == 1)
				fst_stand = (fst_stand + 7) % 8;
			// 반시계방향 일 경우
			else
				fst_stand = (fst_stand + 1) % 8;
		}
		else
			return;
	}
}
int solve(){
	while (!dirQue.empty()){
		pair<int, int> cur = dirQue.front(); dirQue.pop();

		switch (cur.first){
		case 1: firstTurn(cur.second, 1);  break;
		case 2: secondTurn(cur.second, 2); break;
		case 3: thirdTurn(cur.second, 3);  break;
		case 4: fourthTurn(cur.second, 4); break;
		}
	}
	int fSum = first[fst_stand];
	int sSum = second[snd_stand] * 2;
	int tSum = third[tth_stand] * 4;
	int ffSum = fourth[fth_stand] * 8;

	return fSum + sSum + tSum + ffSum;
}
int main(){
	int T, test_case;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		int i, magnetic, dir;

		// --- 변수 초기화 시작 ---
		while (!dirQue.empty())
			dirQue.pop();
		fst_stand = 0;
		snd_stand = 0;
		tth_stand = 0;
		fth_stand = 0;
		// --- 변수 초기화 종료 ---

		// ------ 입력 시작 ------
		scanf("%d", &K);
		for (i = 0; i < 8; ++i)
			scanf("%d", &first[i]);
		for (i = 0; i < 8; ++i)
			scanf("%d", &second[i]);
		for (i = 0; i < 8; ++i)
			scanf("%d", &third[i]);
		for (i = 0; i < 8; ++i)
			scanf("%d", &fourth[i]);
		for (i = 0; i < K; ++i){
			scanf("%d %d", &magnetic, &dir);
			dirQue.push(make_pair(magnetic,dir));
		}
		// ------ 입력 종료 ------


		// ------ 결과 출력 ------
		printf("#%d %d\n", test_case, solve());

	}
	return 0;
}