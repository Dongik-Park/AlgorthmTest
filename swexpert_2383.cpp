#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int N;				// ��, �� ����
int map[11][11];	// �� �Է�
int tempMap[11][11];// �ӽ� ��
int fst_row;	    // ù��° ��� ��
int fst_col;		// ù��° ��� ��
int snd_row;		// �ι�° ��� ��
int snd_col;		// �ι�° ��� ��
queue<int> firstWaitQ;  // ù��° ��� ��� ť
queue<int> firstMoveQ;  // ù��° ��� �̵� ť
queue<int> secondWaitQ; // �ι�° ��� ���ť
queue<int> secondMoveQ; // �ι�° ��� �̵� ť
vector<pair<int, int>> firstList;  // ù��° ����� ������ ��� ���
vector<pair<int, int>> secondList; // �ι�° ����� ������ ��� ���
vector<pair<int, int>> personList; // ��� ��ǥ ���
int cnt_person; // ��� ��

// �ʱ� ������ ����
void recoverMap(){
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			map[i][j] = tempMap[i][j];
}
// map�� ��� 1 (��� ���)�� 0���� (������� �̵��ߴ��� �˻�)
bool isFinished(){
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (map[i][j] == 1)
				return false;
	return true;
}
// ���� Ž�� 
int dfs(int cur_person){
	int result = numeric_limits<int>::max();
	// ���� ��� ��� ������ Ž�� ���� ���
	if (cur_person < cnt_person){
		// ���� ��� ��ǥ ����
		pair<int, int> cur = personList[cur_person];

		// ù��° ��� ��Ͽ� �߰��ϰ�
		firstList.push_back(make_pair(cur.first, cur.second));
		// ���� ��� ������.
		result = min(result, dfs(cur_person + 1));
		// ù��° ������ ��� ����
		firstList.pop_back();

		// �� ����
		recoverMap();

		// �ι�° ��� ��Ͽ� �߰��ϰ�
		secondList.push_back(make_pair(cur.first, cur.second));
		// ���� ��� ������.
		result = min(result, dfs(cur_person + 1));
		// �ι�° ������ ��� ����
		secondList.pop_back();

		// �� ����
		recoverMap();
	}
	// ������ ������� �� ��� ���ݱ��� ������ �������� ��� �ð� ����Ѵ�.
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
		// ��� ����� ���ť �Ǵ� �̵�ť�� �� ��� || �� ���ť�� �̵�ť�� ��� ������� �� ���� �ݺ�
		while (!isFinished() || !firstWaitQ.empty() || !firstMoveQ.empty() || !secondWaitQ.empty() || !secondMoveQ.empty()){
			// ���� ����
			int cur_row, cur_col;
			// ���� �ð� ���� (1�ʺ��ͽ���)
			++cur_time;

			// ------------------------------------  1�� ��� ���� ��ƾ ���� ------------------------------------ 

			// 1�� ������ ��� �߿� ���� �ð� �ȿ� ��� ����� 1�� ��� ��� ť �߰��Ѵ�.
			for (int i = 0; i < firstList.size(); ++i){
				cur_row = firstList[i].first;
				cur_col = firstList[i].second;
				if (map[cur_row][cur_col] == 1 && abs(fst_row - cur_row) + abs(fst_col - cur_col) == cur_time){
					// ť�� �� �ð��� ����Ѵ�.
					firstWaitQ.push(cur_time);
					// �߰��Ǿ����Ƿ� map�� 0���� �����.
					map[cur_row][cur_col] = 0;
				}
			}
			// 1�� ��� �̵� ť�� �̵� �ð��� �Ϸ�� �ο� �ִ��� ã�´�.
			while (!firstMoveQ.empty()){
				int qTime = firstMoveQ.front();
				// �Ϸ�� �ο������� ������.
				if (cur_time == qTime)
					firstMoveQ.pop();
				else
					break;
			}
			// 1�� ��� ��� ť�� �ο� �� 1�� �̻� ��ٸ� ��� ã�´�.
			while (!firstWaitQ.empty()){
				// ���ť�� ���� ������� �����Ѵ�.
				int qTime = firstWaitQ.front();
				// 1�� �̻� ��ٸ� ��� && 1�� ��� �̵� ť�� ������ �ִ��� ������� Ȯ���ϰ� ���� 
				if (cur_time - qTime >= 1 && firstMoveQ.size() < 3){
					// �̵� ť�� ���� ������ ���� ���� �ð��� ����Ѵ�.
					firstMoveQ.push(cur_time + map[fst_row][fst_col]);
					firstWaitQ.pop();
				}
				else
					break;
			}
			// ------------------------------------  1�� ��� ���� ��ƾ ���� ------------------------------------ 


			// ------------------------------------  2�� ��� ���� ��ƾ ���� ------------------------------------ 

			// 2�� ������ ��� �߿� ���� �ð� �ȿ� ��� ����� 2�� ��� ��� ť �߰��Ѵ�.
			for (int i = 0; i < secondList.size(); ++i){
				cur_row = secondList[i].first;
				cur_col = secondList[i].second;
				if (map[cur_row][cur_col] == 1 && abs(snd_row - cur_row) + abs(snd_col - cur_col) == cur_time){
					// ť�� �� �ð��� ����Ѵ�.
					secondWaitQ.push(cur_time);
					// �߰��Ǿ����Ƿ� map�� 0���� �����.
					map[cur_row][cur_col] = 0;
				}
			}
			// 2�� ��� �̵� ť�� �̵� �ð��� �Ϸ�� �ο� �ִ��� ã�´�.
			while (!secondMoveQ.empty()){
				int qTime = secondMoveQ.front();
				// �Ϸ�� �ο������� ������.
				if (cur_time == qTime)
					secondMoveQ.pop();
				else
					break;
			}
			// 2�� ��� ��� ť�� �ο� �� 1�� �̻� ��ٸ� ��� ã�´�.
			while (!secondWaitQ.empty()){
				// ���ť�� ���� ������� �����Ѵ�.
				int qTime = secondWaitQ.front();
				// 1�� �̻� ��ٸ� ��� && 2�� ��� �̵� ť�� ������ �ִ��� ������� Ȯ���ϰ� ���� 
				if (cur_time - qTime >= 1 && secondMoveQ.size() < 3){
					// �̵� ť�� ���� ������ ���� ���� �ð��� ����Ѵ�.
					secondMoveQ.push(cur_time + map[snd_row][snd_col]);
					secondWaitQ.pop();
				}
				else
					break;
			}
			// ------------------------------------  2�� ��� ���� ��ƾ ���� ------------------------------------ 
		}
		// �ش� Ž�� ��� ����
		result = cur_time;
	}
	// �ּ� ��� ��ȯ
	return result;
}
int solve(){
	int time;
	// ��� ��ǥ ����Ʈ �����Ѵ�.
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (map[i][j] == 1)
				personList.push_back(make_pair(i, j));
	// ��� �� ���� ( 1 �̻� )
	cnt_person = personList.size();
	// ���� Ž�� ��� ����
	time = dfs(0);
	// ��� ��ȯ
	return time;
}
int main(){

	int T, test_case;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){

		// ------ �Է� ���� ------
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
		// ------ �Է� ���� ------

		// --- ���� �ʱ�ȭ ���� ---
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
		// --- ���� �ʱ�ȭ ���� ---

		// ------ ��� ��� ------
		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}