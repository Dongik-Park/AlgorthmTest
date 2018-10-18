#include<cstdio>
#include<algorithm>
#include<vector>
#define MAX_N 100
using namespace std;
int map[MAX_N][MAX_N];
int N, X;
int solve(){
	// ����(�Ǵ� ���)���� ����(�Ǵ� �ϴ�)���� ��ĭ�� �̵��س����鼭 �ٸ� ���� ��츦 �˻��Ѵ�.
	//	1-1. ���簪���� ū ��� �׵����� cnt ������ L�̻����� Ȯ��
	//  1-2. ���簪���� ���� ��� �� ��ġ���� L���� ���ӵ� ������ Ȯ���ϰ� �˻� ��ġ�� L��ŭ �ø���.
	bool flag = true;
	int result = 0;
	for (int i = 0; i < N; ++i){
		int target = map[i][0];
		int cnt = 1;
		flag = true;
		for (int j = 1; j < N; ++j){
			if (map[i][j] == target) ++cnt; // ���ӵ� �� �� ���
			else if (abs(map[i][j] - target) > 1) { // �������� 2 �̻� �� ���
				flag = false;
				break;
			}
			else{ // �������� 1�� ���
				if (map[i][j] > target) // ���纸�� ���� ��� (������� count ��)
					if (cnt < X) flag = false;
					else{ // ������ ��� �� ����
						target = map[i][j];
						cnt = 1;
					}
				else{ // ���纸�� ���� ��� ������ L��ŭ�� �����Ų �� j�� �״������� �����Ѵ�.
					int temp_cnt = 0;
					for (int k = j; k < N; ++k){
						if (temp_cnt == X) break;
						if (map[i][j] == map[i][k]) ++temp_cnt;
						else break;
					}
					if (temp_cnt == X){
						j += X - 1;	// ���纸�� ���� ���� L��ŭ �̵� �����ϸ� L - 1�� ���Ѵ�. for���Ŀ� ���� + 1��.
						target = map[i][j]; // ������ġ + L - 1�� ������ ������ ����	(���� ���� ���� �ص� ����)
						cnt = 0;
					}
					else flag = false;
				}
			}
			if (!flag) break;
		}
		if (flag) ++result;
	}
	// ���ι��� �˻�
	for (int i = 0; i < N; ++i){
		int target = map[0][i];
		int cnt = 1;
		flag = true;
		for (int j = 1; j < N; ++j){
			if (map[j][i] == target) ++cnt; // ���ӵ� �� �� ���
			else if (abs(map[j][i] - target) > 1) { // �������� 2 �̻� �� ���
				flag = false;
				break;
			}
			else{ // �������� 1�� ���
				if (map[j][i] > target) // ���纸�� ���� ��� (������� count ��)
					if (cnt < X) flag = false;
					else{
						target = map[j][i];
						cnt = 1;
					}

				else{ // ���纸�� ���� ��� ������ L��ŭ�� �˻� �� �����Ų �� j�� �״������� �����Ѵ�.
					int temp_cnt = 0;
					for (int k = j; k < N; ++k){
						if (temp_cnt == X) break;
						if (map[j][i] == map[k][i]) ++temp_cnt;
						else break;
					}
					if (temp_cnt == X){
						target = map[j][i];
						cnt = 0;
						j += X - 1;	// ���纸�� ���� ���� L��ŭ �̵� �����ϸ� L-1�� ���Ѵ�. for���Ŀ� ���� + 1��.	
					}
					else flag = false;
				}
			}
			if (!flag) break;
		}
		if (flag) ++result;
	}

	return result;
}
int main(){
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d", &N, &X);

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				scanf("%d", &map[i][j]);

		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}