#include <stdio.h>
int init(int(*a)[2]);
int main() {
	int arr[100][2] = { 0 };
	int map[102] = { 0 };
	int temp = 0, i, j, test_case, count;


	while (scanf("%d", &test_case) != EOF) {
		count = init(arr);
		for (i = 1; i < 100; ++i) {
			for (j = 1; j <= 100; ++j) {
				scanf("%d", &temp);
				map[j] = temp;
			}
			for (j = 0; j < count; ++j) {
				temp = arr[j][1];
				if (map[temp + 1] > 0) {
					while (map[temp] != 0) {
						temp++;
					}
					arr[j][1] = temp - 1;
				}
				else if (map[temp - 1] > 0) {
					while (map[temp] != 0) {
						temp--;
					}
					arr[j][1] = temp + 1;
				}

			}
		}
		printf("#%d ", test_case);
		for (i = 0; i < count; ++i) {
			if (map[arr[i][1]] == 2) {
				printf("%d\n", arr[i][0] - 1);
				break;
			}
		}
	}

	return 0;
}
int init(int(*a)[2]) {
	int i, count = 0, temp;
	for (i = 1; i <= 100; ++i) {
		scanf("%d", &temp);
		if (temp) {
			a[count][0] = i;
			a[count][1] = i;

			count++;
		}
	}
	return count;
}