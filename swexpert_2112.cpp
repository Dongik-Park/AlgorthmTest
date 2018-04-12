#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int D; // �β�
int W; // �ʺ�
int K; // ��� ���� 
int map[14][21];	// ��ȣ�ʸ� �ܸ�
int tempMap[14][21];// ��ȣ�ʸ� �ܸ� ������ ���� ��
int chooseNum;		// ���� ������ ���� ����
int visited[14];    // ���� �湮�ߴ��� ����
int tempVisited[14];// �� �湮�� �����ϱ� ���� �迭

// ���� �˻縦 ����ϴ��� Ȯ��
bool checkPass(){
	int cnt = 0;
	int target;
	bool flag;
	for (int i = 1; i <= W; ++i){
		target = map[1][i];
		cnt = 1;
		flag = false;
		for (int j = 2; j <= D; ++j){
			// ������ ���� 1����
			if (target == map[j][i]){
				++cnt;
				// K�� ������ ��� ��
				if (cnt == K){
					flag = true;
					break;
				}
			}
			// �ٸ��� target�� cnt ����
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
// �� ������ ���� ������ ���� �Ϸ��ߴ���
bool isVisited(){
	int cnt = 0;
	for (int i = 1; i <= D; ++i)
		if (visited[i] == 1)
			++cnt;
	if (cnt == chooseNum)
		return true;
	return false;
}
// map ����
void recoverMap(){
	for (int i = 1; i <= D; ++i)
		for (int j = 1; j <= W; ++j)
			map[i][j] = tempMap[i][j];
}
// visited ����
void recoverVisited(){
	for (int i = 1; i <= D; ++i)
		visited[i] = tempVisited[i];
}
// ������ ���� ������ ���� ����� ��ȯ�Ѵ�.
int dfs2(int visitD){
	visited[visitD] = 0;
	bool flag = false;
	int next;
	// �������� �湮�ؾ��� ���� �����ϴ� �� Ȯ��
	for (next = visitD; next <= D; ++next)
		if (visited[next] == 1)
			break;
	// �� �湮�� ���� ���� �˻� �� ��� ��ȯ
	if (next == D + 1){
		// A ��ǰ�� ������ ���
		for (int i = 1; i <= W; ++i)
			map[visitD][i] = 0;
		// ��� Ȯ��
		flag = checkPass();
		// A ��ǰ ���������� �������� �ʴ´�.
		if (!flag){
			// B�� ������ ���
			for (int i = 1; i <= W; ++i)
				map[visitD][i] = 1;
			// ��� Ȯ��
			flag = checkPass();
		}
	}
	// �������� �� �湮�� ���� �ִ� ��� ��� ȣ��
	else{
		// A ��ǰ�� ������ ���
		for (int i = 1; i <= W; ++i)
			map[visitD][i] = 0;
		flag = dfs2(next);
		// A ��ǰ ���������� �������� �ʴ´�..
		if (!flag){
			// B�� ������ ���
			for (int i = 1; i <= W; ++i)
				map[visitD][i] = 1;
			flag = dfs2(next);
		}
	}
	return flag;
}
// ������ ���� 1 ~ K�� �� �����ϱ� ���� ��� �Լ�
int dfs(int curD){
	bool flag = false;
	// ���� ���� ������ �Ϸ�� ���
	if (isVisited()){
		// �湮 ���� ����
		for (int i = 1; i <= D; ++i)
			tempVisited[i] = visited[i];
		// ���� ������ ���� �������� �˻��Ѵ�.
		for (int i = 1; i <= D; ++i)
			if (visited[i] == 1){
				flag = dfs2(i);
				break;
			}
		// �� ����
		recoverMap();
		recoverVisited();
		return flag;
	}
	if (curD > D)
		return false;
	
	// ���� ���� �����ϴ� ���
	visited[curD] = 1;
	flag = dfs(curD + 1);

	// ���� ���� �������� �ʴ� ���
	visited[curD] = 0;
	// ���� ������ ����Ǿ����� �������� �ʴ´�.
	if (!flag){
		flag = dfs(curD + 1);
	}
	return flag;
}
int solve(){
	// ��ǰ�� �������� �ʰ� ���� �˻縦 ����ϴ� ���
	if (checkPass())
		return 0;
	// ��ǰ�� ������ ���� ������ �����ϴ� ��� ȣ�� ( 1 ~ K )
	// K�� ��� �������� ������ ���� �����ϸ� �ݵ�� ����Ѵ�.
	int i;
	for (i = 1; i <= K; ++i){
		chooseNum = i;
		if (dfs(1))
			break;
	}
	// ��� ��ȯ
	if (i != K + 1)
		return i;
	return 0;
}
int main(){
	int T, test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case){
		// ------ �Է� ���� ------
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 1; i <= D; ++i)
			for (int j = 1; j <= W; ++j){
				scanf("%d", &map[i][j]);
				tempMap[i][j] = map[i][j];
			}
		// ------ �Է� ���� ------

		// ------ ��� ��� ------
		printf("#%d %d\n", test_case, solve());
	}
	return 0;
}