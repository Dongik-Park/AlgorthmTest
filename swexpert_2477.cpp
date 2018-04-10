#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int N, M, K, A, B; // ���� â��, ���� â��, �湮 �� ��, �н� �� ���� â�� ��ȣ, �н� �� ���� â�� ��ȣ
int N_map[10];     // ���� â�� ������� ó�� ���� �ð�
int M_map[10];     // ���� â�� ������� ó�� ���� �ð�
int tk[1001];	   // ������ ����� ���� �ð�
int N_used[10];    // ���� ���� â���� �̿����� �� ��ȣ
int M_used[10];    // ���� ���� â���� �̿� ���� �� ��ȣ
int N_visited_time[10]; // ���� ���� ���� �� �ִ� �ð� ( ����ð� + â�� ������� ó�� ���� �ð� )
int M_visited_time[10]; // ���� ���� ���� �� �ִ� �ð� ( ����ð� + â�� ������� ó�� ���� �ð� )
int N_num[1001];   // k�� ���� �ο����� ���� â�� ��ȣ
int M_num[1001];   // k�� ���� �ο����� ���� â�� ��ȣ
int cur_time;	   // ���� �ð�
queue<int> firstQ; //���� â�� ��� ť
queue<int> secondQ;//���� â�� ��� ť

// ��� ������ ������ ���� â���� �湮�ߴ���
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
// ���� â���� �� ����
int insertToM(int customerNum){
	int i;
	for (i = 1; i <= M; ++i)
		if (!M_used[i]){
			// ����â���� �� ����
			M_used[i] = customerNum;
			// �� �湮�ð� + ó���ð� ����
			M_visited_time[i] = cur_time + M_map[i];
			// ���� �湮�� ����â�� ��ȣ ����
			M_num[customerNum] = i;
			break;
		}
	if (i == M + 1)
		return -1;
	return i;
}
// ���� �ð� ���� ���� â�� �̿� �Ϸ� �� Ȯ��
void checkM(){
	for (int i = 1; i <= M; ++i)
		// ���� �ð��� ����â�� ó�� �Ϸ�� ��������
		if (cur_time == M_visited_time[i]){
			// �ش� ���� â�� �� ó�� �ð� �ʱ�ȭ
			M_visited_time[i] = -1;
			// �ش� ���� â�� �� ��ȣ �ʱ�ȭ
			M_used[i] = 0;
		}
}
// ���� �ð� ���� ���� â�� �̿� �Ϸ� �� Ȯ��
void checkN(){
	// ���� â�� ��ȣ�� ���� ������� ����.
	for (int i = 1; i <= N; ++i)
		// ���� �ð��� ����â�� ó�� �Ϸ�� ��������
		if (cur_time == N_visited_time[i]){
			// ����â�� ���ť�� �����ϰ�
			secondQ.push(N_used[i]);
			// �ش� ���� â�� �� ó�� �ð� �ʱ�ȭ
			N_visited_time[i] = -1;
			// �ش� ���� â�� �� ��ȣ �ʱ�ȭ
			N_used[i] = 0;
		}
}
// ���� â���� �� ����
int insertToN(int customerNum){
	int i;
	for (i = 1; i <= N; ++i)
		if (!N_used[i]){
			// ����â���� �� ����
			N_used[i] = customerNum;
			// ���� �湮 �ð� + ó���ð� ����
			N_visited_time[i] = cur_time + N_map[i];
			// ���� �湮�� ����â�� ��ȣ ����
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
		//�� �� ������� ���� â�� ť�� ���
		for (i = 1; i <= K; ++i)
			if (cur_time == tk[i])
				firstQ.push(i);
			else if (cur_time < tk[i])
				break;
		//����ð� ���ؿ� ó���� ���� ����â���� ��� �� ���� â�� ����
		checkN();
		// ����ϰ� �ִ� ��������
		if (!firstQ.empty()){
			int customerNum = firstQ.front();
			// ����â���� ���� ������ ��� ��� ����
			while (insertToN(customerNum) != -1){
				// �����Ǿ����� ť���� ����
				firstQ.pop();
				if (!firstQ.empty())
					customerNum = firstQ.front();
				else
					break;
			}
		}

		//����ð� ���ؿ� ó���� ���� ���� â�� ����
		checkM();
		// ����ϰ� �ִ� ��������
		if (!secondQ.empty()){
			int customerNum = secondQ.front();
			// ����â���� ���� ������ ��� ��� ����
			while (insertToM(customerNum) != -1){
				// �Ҵ�Ǿ����� ť���� ����
				secondQ.pop();
				if (!secondQ.empty())
					customerNum = secondQ.front();
				else
					break;
			}
		}

		// ���� �ð� ����
		++cur_time;
	}
	// ����, ���� â�� ��ȣ Ȯ�� �� ��� ��ȯ
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
		// ------ �Է� ���� ------
		for (i = 1; i <= N; ++i)
			scanf("%d", &N_map[i]);
		for (i = 1; i <= M; ++i)
			scanf("%d", &M_map[i]);
		for (i = 1; i <= K; ++i)
			scanf("%d", &tk[i]);
		// ------ �Է� ���� ------

		// --- ���� �ʱ�ȭ ���� ---
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
		// --- ���� �ʱ�ȭ ���� ---

		// ------ ��� ��� ------
		printf("#%d %d\n", test_case, solve());
	}
	return 0;
}