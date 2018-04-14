#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int N, K;		   // ��,���� ��, ���� �� �ִ� �ִ� ���츮 ��
int map[9][9];	   // ���� �迭
int visited[9][9]; // �湮 üũ
int dx[4] = { -1, 1, 0, 0 };		  // ��, ��, ��, ��
int dy[4] = { 0, 0, -1, 1 };		  // ��, ��, ��, ��
vector<pair<int, int>> maxHeightList; // �ְ� ���� ���츮 ���

// ���� �ȿ� ����� Ȯ��
bool inRange(int row, int col){
	if (row >= 0 && row < N && col >= 0 && col < N)
		return true;
	return false;
}
int dfs(int row, int col, int cnt){
	int nrow, ncol;
	int val = 0;
	bool flag = false;
	// �����¿� �˻��Ͽ� ��� ȣ��
	for (int i = 0; i < 4; ++i){
		nrow = row + dx[i];
		ncol = col + dy[i];
		// �迭 ���� �� || ���� ������ ���� ���� || �湮���� ���� ��
		if (inRange(nrow, ncol) && map[row][col] > map[nrow][ncol] && !visited[nrow][ncol]){
			visited[nrow][ncol] = 1;
			val = max(val, dfs(nrow, ncol, cnt + 1));
			visited[nrow][ncol] = 0;
			flag = true;
		}
	}
	// 4�� ��� �湮 �Ұ����� ���
	if (!flag)
		return cnt;
	return val;
}
int solve(){

	// �湮 �� �ʱ�ȭ
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			visited[i][j] = 0;

	// ���� �ʱ�ȭ
	while (!maxHeightList.empty())
		maxHeightList.pop_back();

	// �ִ밪 ���� ����
	int temp = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			temp = max(temp, map[i][j]);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (map[i][j] == temp)
				maxHeightList.push_back(make_pair(i, j));

	// �� ���� K�� ���� �ʾ��� ���
	int maxVal = 0;
	for (int i = 0; i < maxHeightList.size(); ++i)
		maxVal = max(maxVal, dfs(maxHeightList[i].first, maxHeightList[i].second, 1));

	// �� ���� K�� ���� ���
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j){
			// ��� ����� �ִ� �� �߿� ���ԵǴ��� Ȯ��
			bool flag = false;
			for (int k = 0; k < maxHeightList.size(); ++k)
				// ���Ե� ��� �ӽ� ����
				if (maxHeightList[k].first == i && maxHeightList[k].second == j){
					maxHeightList.erase(maxHeightList.begin() + k);
					flag = true;
					break;
				}
			// 1 ~ K ���� ���� �� �ִ�.
			for (int l = 1; l <= K; ++l){
				map[i][j] -= l;
				// �ִ� ���츮���� Ž�� ����
				for (int k = 0; k < maxHeightList.size(); ++k){
					maxVal = max(maxVal, dfs(maxHeightList[k].first, maxHeightList[k].second, 1));
				}
				map[i][j] += l;
			}
			// ��� ����� �ִ� ���̾� �ӽ� ������ ��� ����
			if (flag)
				maxHeightList.push_back(make_pair(i, j));
		}
	return maxVal;
}
int main(){

	int T, test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case){

		// ------ �Է� ���� ------
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				scanf("%d", &map[i][j]);
		// ------ �Է� ���� ------

		// ------ ��� ��� ------
		printf("#%d %d\n", test_case, solve());
	}
	return 0;
}