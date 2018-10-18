#include<cstdio>
#include<algorithm>
#include<vector>
#define MAX_N 100
using namespace std;
int map[MAX_N][MAX_N];
int N, X;
int solve(){
	// 왼쪽(또는 상단)부터 우측(또는 하단)까지 한칸씩 이동해나가면서 다른 값일 경우를 검사한다.
	//	1-1. 현재값보다 큰 경우 그동안의 cnt 개수가 L이상인지 확인
	//  1-2. 현재값보다 작은 경우 그 위치부터 L까지 연속된 수인지 확인하고 검사 위치를 L만큼 늘린다.
	bool flag = true;
	int result = 0;
	for (int i = 0; i < N; ++i){
		int target = map[i][0];
		int cnt = 1;
		flag = true;
		for (int j = 1; j < N; ++j){
			if (map[i][j] == target) ++cnt; // 연속된 수 일 경우
			else if (abs(map[i][j] - target) > 1) { // 높이차가 2 이상 날 경우
				flag = false;
				break;
			}
			else{ // 높이차가 1일 경우
				if (map[i][j] > target) // 현재보다 높을 경우 (현재까지 count 비교)
					if (cnt < X) flag = false;
					else{ // 가능할 경우 값 갱신
						target = map[i][j];
						cnt = 1;
					}
				else{ // 현재보다 낮을 경우 앞으로 L만큼만 진행시킨 후 j를 그다음으로 갱신한다.
					int temp_cnt = 0;
					for (int k = j; k < N; ++k){
						if (temp_cnt == X) break;
						if (map[i][j] == map[i][k]) ++temp_cnt;
						else break;
					}
					if (temp_cnt == X){
						j += X - 1;	// 현재보다 낮은 경사로 L만큼 이동 가능하면 L - 1을 더한다. for문식에 의해 + 1됨.
						target = map[i][j]; // 현재위치 + L - 1의 지점의 값으로 갱신	(위의 라인 위에 해도 동일)
						cnt = 0;
					}
					else flag = false;
				}
			}
			if (!flag) break;
		}
		if (flag) ++result;
	}
	// 세로방향 검사
	for (int i = 0; i < N; ++i){
		int target = map[0][i];
		int cnt = 1;
		flag = true;
		for (int j = 1; j < N; ++j){
			if (map[j][i] == target) ++cnt; // 연속된 수 일 경우
			else if (abs(map[j][i] - target) > 1) { // 높이차가 2 이상 날 경우
				flag = false;
				break;
			}
			else{ // 높이차가 1일 경우
				if (map[j][i] > target) // 현재보다 높을 경우 (현재까지 count 비교)
					if (cnt < X) flag = false;
					else{
						target = map[j][i];
						cnt = 1;
					}

				else{ // 현재보다 낮을 경우 앞으로 L만큼만 검사 및 진행시킨 후 j를 그다음으로 갱신한다.
					int temp_cnt = 0;
					for (int k = j; k < N; ++k){
						if (temp_cnt == X) break;
						if (map[j][i] == map[k][i]) ++temp_cnt;
						else break;
					}
					if (temp_cnt == X){
						target = map[j][i];
						cnt = 0;
						j += X - 1;	// 현재보다 낮은 경사로 L만큼 이동 가능하면 L-1을 더한다. for문식에 의해 + 1됨.	
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