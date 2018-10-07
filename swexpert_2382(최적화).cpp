#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX_N 100
using namespace std;

struct Microbe{
	int row;
	int col;
	int cnt;
	int dir;
	bool active;
};

int N, M, K; // ���� ����, �ݸ� �ð�, �̻��� ���� ��
int dx[4] = { -1, 0, 1, 0 }; // �����Ͽ�
int dy[4] = { 0, -1, 0, 1 };
int map[MAX_N][MAX_N];
vector<Microbe> list;

// ��ǰ �ȿ� �����ϴ��� Ȯ��
bool inRange(int row, int col){
	if (row > 0 && row < N - 1 && col > 0 && col < N - 1)
		return true;
	return false;
}

int solve(){

	// 1. ������ �̵���Ű�� ���� �����Ѵ�.
	// 2. ��ǰ�� ��Ҵ��� Ȯ���Ѵ�. 
	//     -> ����� ��� : ������ / 2
	//	   -> 0�� ��� ���� ����	
	//	   -> �̵����� ����
	// 3. map�� count�� ������Ų��.
	// 4. �ߺ��Ǵ� ����(map�� count�� 2�̻�)�� �ִ��� Ȯ���Ѵ�. 
	//	   -> �ߺ��� ��� : 1. �ش� ��ǥ�� �̻����� �� �������� ���� ���� ���� ã�´�.
	//	   ->			    2. ���� ���� �������� �������� ��ġ�� �������� ����

	while (M-- != 0){
		for (int i = 0; i < list.size(); ++i){
			if (!list[i].active)
				continue;
			// 1. ������ �̵���Ű�� ���� �����Ѵ�.
			int n_row = list[i].row + dx[list[i].dir];
			int n_col = list[i].col + dy[list[i].dir];
			list[i].row = n_row;
			list[i].col = n_col;
			// 2. ��ǰ�� ����� ���
			if (!inRange(n_row, n_col)){
				// ���� 1/2
				list[i].cnt = list[i].cnt / 2;
				// 0�̵� ��� ��Ȱ��ȭ
				if (list[i].cnt == 0){
					list[i].active = false;
					continue;
				}
				// ���� �ݴ� ����
				list[i].dir = (list[i].dir + 2) % 4;
			}
			// 3. map count ����
			++map[n_row][n_col];
		}
		// 4. �ߺ��Ǵ� ������ �ִ��� Ȯ���Ѵ�. ( �ߺ��� ��� �� ��ġ�� �̵����� ���� ������ )
		for (int i = 0; i < list.size(); ++i){
			if (!list[i].active) continue;
			int row = list[i].row;
			int col = list[i].col;
			// 2�� �̻��� �̻����� ��ġ�� ���
			if (map[row][col] > 1){
				vector<int> temp;
				int max_index = i;
				temp.push_back(i);
				// ���� �������� ���� �̻����� index�� ã�´�.
				for (int j = i + 1; j < list.size(); ++j){
					if (!list[j].active) continue;
					if (row == list[j].row && col == list[j].col){
						temp.push_back(j);
						if (list[max_index].cnt < list[j].cnt)
							max_index = j;
					}
				}
				// �ش� index�� �������� �߰��ϰ� �������� ��Ȱ��ȭ
				for (int j = 0; j < temp.size(); ++j)
					if (temp[j] != max_index){
						list[max_index].cnt += list[temp[j]].cnt;
						list[temp[j]].active = false;
					}
			}
			// map count �ʱ�ȭ
			map[row][col] = 0;
		}
	}
	// ����ִ� �̻��� ���� ���� ���� ��ȯ
	int sum = 0;
	for (int i = 0; i < list.size(); ++i)
		if (list[i].active)
			sum += list[i].cnt;
	return sum;
}

int main(){

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d %d", &N, &M, &K);
		// �̻��� ����Ʈ �ʱ�ȭ
		while (!list.empty()) list.pop_back();
		// �̻��� �Է�
		for (int i = 0; i < K; ++i){
			Microbe microbe;
			// �����¿� 1234
			scanf("%d %d %d %d", &microbe.row, &microbe.col, &microbe.cnt, &microbe.dir);
			// �����¿� 0123
			--microbe.dir;
			// �����¿� 0213
			if (microbe.dir == 1)      microbe.dir = 2;
			else if (microbe.dir == 2) microbe.dir = 1;
			microbe.active = true;
			list.push_back(microbe);
		}

		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}