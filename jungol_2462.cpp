#include <stdio.h>
#define INF 987654321
int N, M, ans = 0;
int arr[505][505];
int isConnected[505] = { 0, };
/*
	플로이드워샬 알고리즘을 활용하여 그래프 간 모든 정점 간의 최단 거리를 찾는다.
	이를 인접행렬로 만들고 난 후, 각 index에 대해 행과 열의 합이 N - 1인 경우 정답 count를 1씩 늘린다.
*/
int main() {

	scanf_s("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = INF;
		}
	}

	while (M--) {
		int a, b;
		scanf_s("%d%d", &a, &b);
		arr[a][b] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];

	/*    
		for(int i=1;i<=N;i++){
	        for(int j=1;j<=N;j++){
	            if(arr[i][j]==INF) printf("$ ");
	            else printf("%d ",arr[i][j]);
	        }
	        printf("\n");
	 }*/

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] != INF) {
				isConnected[i]++, isConnected[j]++;
				if (isConnected[i] == N - 1) ans++;
				if (isConnected[j] == N - 1) ans++;
			}
		}
	}

	// for(int i=1;i<=N;i++) printf("%d ",isConnected[i]);

	printf("%d", ans);
}