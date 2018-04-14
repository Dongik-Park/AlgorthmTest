#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int N, K;		   // 행,열의 수, 깎을 수 있는 최대 봉우리 수
int map[9][9];	   // 등산로 배열
int visited[9][9]; // 방문 체크
int dx[4] = { -1, 1, 0, 0 };		  // 상, 하, 좌, 우
int dy[4] = { 0, 0, -1, 1 };		  // 상, 하, 좌, 우
vector<pair<int, int>> maxHeightList; // 최고 높이 봉우리 목록

// 범위 안에 드는지 확인
bool inRange(int row, int col){
	if (row >= 0 && row < N && col >= 0 && col < N)
		return true;
	return false;
}
int dfs(int row, int col, int cnt){
	int nrow, ncol;
	int val = 0;
	bool flag = false;
	// 상하좌우 검사하여 재귀 호출
	for (int i = 0; i < 4; ++i){
		nrow = row + dx[i];
		ncol = col + dy[i];
		// 배열 범위 안 || 현재 값보다 낮은 지형 || 방문하지 않은 곳
		if (inRange(nrow, ncol) && map[row][col] > map[nrow][ncol] && !visited[nrow][ncol]){
			visited[nrow][ncol] = 1;
			val = max(val, dfs(nrow, ncol, cnt + 1));
			visited[nrow][ncol] = 0;
			flag = true;
		}
	}
	// 4면 모두 방문 불가능할 경우
	if (!flag)
		return cnt;
	return val;
}
int solve(){

	// 방문 맵 초기화
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			visited[i][j] = 0;

	// 벡터 초기화
	while (!maxHeightList.empty())
		maxHeightList.pop_back();

	// 최대값 벡터 생성
	int temp = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			temp = max(temp, map[i][j]);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (map[i][j] == temp)
				maxHeightList.push_back(make_pair(i, j));

	// 한 곳도 K로 깎지 않았을 경우
	int maxVal = 0;
	for (int i = 0; i < maxHeightList.size(); ++i)
		maxVal = max(maxVal, dfs(maxHeightList[i].first, maxHeightList[i].second, 1));

	// 한 곳의 K를 깎은 경우
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j){
			// 깎는 대상이 최대 값 중에 포함되는지 확인
			bool flag = false;
			for (int k = 0; k < maxHeightList.size(); ++k)
				// 포함될 경우 임시 삭제
				if (maxHeightList[k].first == i && maxHeightList[k].second == j){
					maxHeightList.erase(maxHeightList.begin() + k);
					flag = true;
					break;
				}
			// 1 ~ K 까지 깎을 수 있다.
			for (int l = 1; l <= K; ++l){
				map[i][j] -= l;
				// 최대 봉우리부터 탐색 시작
				for (int k = 0; k < maxHeightList.size(); ++k){
					maxVal = max(maxVal, dfs(maxHeightList[k].first, maxHeightList[k].second, 1));
				}
				map[i][j] += l;
			}
			// 깎는 대상이 최대 값이어 임시 삭제한 경우 복구
			if (flag)
				maxHeightList.push_back(make_pair(i, j));
		}
	return maxVal;
}
int main(){

	int T, test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case){

		// ------ 입력 시작 ------
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				scanf("%d", &map[i][j]);
		// ------ 입력 종료 ------

		// ------ 결과 출력 ------
		printf("#%d %d\n", test_case, solve());
	}
	return 0;
}