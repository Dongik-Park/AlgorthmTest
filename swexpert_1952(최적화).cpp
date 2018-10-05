#include <stdio.h>
#define MAX_MONTH 12

int day, month, quarter, year;
int schedule[MAX_MONTH + 1];

int min(int a, int b){
	return a > b ? b : a;
}

int solve(){
	int cost[MAX_MONTH + 1];
	cost[0] = 0;
	for (int i = 1; i <= MAX_MONTH; ++i){
		// Dynamic Programming�� Ȱ���Ͽ� �����ޱ����� �ּҰ� + ���� ���� ����� �� �� �ּҰ����� �����س�����.
		cost[i] = min(cost[i - 1] + day * schedule[i],
					  cost[i - 1] + month);
		// 3���� �̻��� ��� ���ŵ� �ּҰ��� 3���� ���� ��� + �б� ���� ���Ѵ�.
		if (i >= 3)
			cost[i] = min(cost[i], cost[i - 3] + quarter);
	}
	// 1�� �̿�ǰ� �� ����� ��ȯ
	return min(year, cost[MAX_MONTH]);
}
int main(){
	
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d %d %d", &day, &month, &quarter, &year);

		for (int i = 1; i <= MAX_MONTH; ++i)
			scanf("%d", &schedule[i]);

		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}