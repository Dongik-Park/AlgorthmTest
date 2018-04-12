#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int D; // 두께
int W; // 너비
int K; // 통과 개수 
int map[14][21];	// 보호필름 단면
int tempMap[14][21];// 보호필름 단면 복구를 위한 맵
int chooseNum;		// 약을 투여할 막의 개수
int visited[14];    // 막을 방문했는지 여부
int tempVisited[14];// 막 방문을 복구하기 위한 배열

// 성능 검사를 통과하는지 확인
bool checkPass(){
	int cnt = 0;
	int target;
	bool flag;
	for (int i = 1; i <= W; ++i){
		target = map[1][i];
		cnt = 1;
		flag = false;
		for (int j = 2; j <= D; ++j){
			// 같으면 개수 1증가
			if (target == map[j][i]){
				++cnt;
				// K와 동일할 경우 참
				if (cnt == K){
					flag = true;
					break;
				}
			}
			// 다르면 target과 cnt 갱신
			else{
				target = map[j][i];
				cnt = 1;
			}
		}
		if (!flag)
			break;
	}
	return flag;
}
// 약 투여할 막의 집합을 선택 완료했는지
bool isVisited(){
	int cnt = 0;
	for (int i = 1; i <= D; ++i)
		if (visited[i] == 1)
			++cnt;
	if (cnt == chooseNum)
		return true;
	return false;
}
// map 복구
void recoverMap(){
	for (int i = 1; i <= D; ++i)
		for (int j = 1; j <= W; ++j)
			map[i][j] = tempMap[i][j];
}
// visited 복구
void recoverVisited(){
	for (int i = 1; i <= D; ++i)
		visited[i] = tempVisited[i];
}
// 정해진 막의 집합을 통해 결과를 반환한다.
int dfs2(int visitD){
	visited[visitD] = 0;
	bool flag = false;
	int next;
	// 다음으로 방문해야할 막이 존재하는 지 확인
	for (next = visitD; next <= D; ++next)
		if (visited[next] == 1)
			break;
	// 더 방문할 막이 없을 검사 후 결과 반환
	if (next == D + 1){
		// A 약품을 투여할 경우
		for (int i = 1; i <= W; ++i)
			map[visitD][i] = 0;
		// 결과 확인
		flag = checkPass();
		// A 약품 만족했으면 수행하지 않는다.
		if (!flag){
			// B를 선택한 경우
			for (int i = 1; i <= W; ++i)
				map[visitD][i] = 1;
			// 결과 확인
			flag = checkPass();
		}
	}
	// 다음으로 더 방문할 막이 있는 경우 재귀 호출
	else{
		// A 약품을 투여할 경우
		for (int i = 1; i <= W; ++i)
			map[visitD][i] = 0;
		flag = dfs2(next);
		// A 약품 만족했으면 수행하지 않는다..
		if (!flag){
			// B를 선택한 경우
			for (int i = 1; i <= W; ++i)
				map[visitD][i] = 1;
			flag = dfs2(next);
		}
	}
	return flag;
}
// 투여할 막을 1 ~ K개 중 선택하기 위한 재귀 함수
int dfs(int curD){
	bool flag = false;
	// 막의 집합 선정이 완료된 경우
	if (isVisited()){
		// 방문 여부 복사
		for (int i = 1; i <= D; ++i)
			tempVisited[i] = visited[i];
		// 현재 선정된 막의 집합으로 검색한다.
		for (int i = 1; i <= D; ++i)
			if (visited[i] == 1){
				flag = dfs2(i);
				break;
			}
		// 값 복구
		recoverMap();
		recoverVisited();
		return flag;
	}
	if (curD > D)
		return false;
	
	// 현재 막을 포함하는 경우
	visited[curD] = 1;
	flag = dfs(curD + 1);

	// 현재 막을 포함하지 않는 경우
	visited[curD] = 0;
	// 현재 막에서 통과되었으면 수행하지 않는다.
	if (!flag){
		flag = dfs(curD + 1);
	}
	return flag;
}
int solve(){
	// 약품을 투입하지 않고 성능 검사를 통과하는 경우
	if (checkPass())
		return 0;
	// 약품을 투입할 막의 집합을 선정하는 재귀 호출 ( 1 ~ K )
	// K일 경우 연속으로 동일한 약을 투여하면 반드시 통과한다.
	int i;
	for (i = 1; i <= K; ++i){
		chooseNum = i;
		if (dfs(1))
			break;
	}
	// 결과 반환
	if (i != K + 1)
		return i;
	return 0;
}
int main(){
	int T, test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case){
		// ------ 입력 시작 ------
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 1; i <= D; ++i)
			for (int j = 1; j <= W; ++j){
				scanf("%d", &map[i][j]);
				tempMap[i][j] = map[i][j];
			}
		// ------ 입력 종료 ------

		// ------ 결과 출력 ------
		printf("#%d %d\n", test_case, solve());
	}
	return 0;
}