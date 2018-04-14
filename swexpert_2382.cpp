#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

// �̻��� ���� ����
struct BioInfo{
	int dir;
	int row;
	int col;
	int cnt;
	bool flag;
};

int N, M, K; // ��,���� ��, �ݸ� �ð�, �̻��� ���� ��
int map[101][101];
int dx[5] = { -1, 0, 1, 0 }; // �� : 0, �� : 1, �� : 2, �� : 3
int dy[5] = { 0, -1, 0, 1 }; // �� : 0, �� : 1, �� : 2, �� : 3
BioInfo bios[1001]; // �̻��� ���� �迭

// �̻����� ���� 0�̾� ������� ��� Ȯ��
void vanishCheck(){
	for (int i = 0; i < K; ++i)
		if (bios[i].cnt == 0)
			bios[i].flag = false;
}
// �̻����� �������� ��, ������ üũ
void combineCheck(){
	int cur_row, cur_col;
	// ������ �̻����� index�� ���� ����
	vector<int> temp;
	for (int i = 0; i < K; ++i)
		if (bios[i].flag){
			while (!temp.empty())
				temp.pop_back();
			temp.push_back(i);
			cur_row = bios[i].row;
			cur_col = bios[i].col;
			for (int j = i + 1; j < K; ++j){
				// ����ִ� �̻��� && �̻��� ��� ���� ���� ��� ���Ϳ� �߰�
				if (bios[j].flag && bios[j].row == cur_row && bios[j].col == cur_col)
					temp.push_back(j);
			}
			// ���� ��ġ�� �̻����� 2�� �̻��� ���
			if (temp.size() > 1){
				// ���� 0����
				int maxCnt = bios[temp[0]].cnt;
				int targetIndex = 0;
				// ���� ū ���� ã�´� + ���ÿ� ���� ū ���� index�� ã�´�.
				for (int k = 1; k < temp.size(); ++k){
					if (bios[temp[k]].cnt > maxCnt){
						maxCnt = bios[temp[k]].cnt;
						targetIndex = k;
					}
				}
				// ã�� �ִ� �̻��� �� ��ü�� ����� �������� ��Ȱ��ȭ ��Ų��.
				int sum = 0;
				for (int k = 0; k < temp.size(); ++k){
					sum += bios[temp[k]].cnt;
					// �ִ� �̻��� �ƴ� ��� 
					if (k != targetIndex)
						bios[temp[k]].flag = false;
				}
				// �̻����� ���� ���ϰ� �������� �״��
				bios[temp[targetIndex]].cnt = sum;
			}
		}
}
int solve(){

	// �� �ʱ�ȭ
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			map[i][j] = 0;

	// �� ǥ�� 
	for (int i = 0; i < N; ++i){
		map[i][0] = 1;
		map[0][i] = 1;
		map[N - 1 - i][N - 1] = 1;
		map[N - 1][N - 1 - i] = 1;
	}

	// 1�� ���� M�� ���� �ݺ�
	int nrow, ncol;
	for (int i = 1; i <= M; ++i){
		// ����ִ� �̻��� ��ŭ �ݺ�
		for (int j = 0; j < K; ++j){
			if (bios[j].flag){
				// �̵��� ��, �� ����
				nrow = bios[j].row + dx[bios[j].dir];
				ncol = bios[j].col + dy[bios[j].dir];
				bios[j].row = nrow;
				bios[j].col = ncol;
				// �̵��� ���� ���� ���
				if (map[nrow][ncol] == 1){
					// �̻��� �� ����
					bios[j].cnt = (int)(bios[j].cnt / 2);
					// ���� ����
					bios[j].dir = (bios[j].dir + 2) % 4;
				}
			}
		}
		// 1�ʸ��� ������� �̻��� �˻�
		vanishCheck();
		// 1�ʸ��� �������� �̻��� �˻�
		combineCheck();
	}
	// ��� ��ȯ
	int sum = 0;
	for (int i = 0; i < K; ++i){
		if (bios[i].flag)
			sum += bios[i].cnt;
	}
	return sum;
}
int main(){
	int T, test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case){

		// ------ �Է� ���� ------
		scanf("%d %d %d", &N, &M, &K);
		int row, col, cnt, dir;
		for (int i = 0; i < K; ++i){
			scanf("%d %d %d %d", &row, &col, &cnt, &dir);
			// �Է� dir ( ���� : �� : 1, �� : 2, �� : 3, �� : 4) -> ������ : �� : 0, �� : 1, �� : 2, �� : 3 �� ����)
			if (dir == 2)
				dir = 3;
			else if (dir == 3)
				dir = 2;
			BioInfo bio;
			bio.row = row;
			bio.col = col;
			bio.cnt = cnt;
			bio.dir = dir - 1;
			bio.flag = true;
			bios[i] = bio;
		}
		// ------ �Է� ���� ------

		// ------ ��� ��� ------
		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}