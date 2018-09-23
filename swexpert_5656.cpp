#include<cstdio>

#define MAX_W 12
#define MAX_H 15

using namespace std;

int N, H, W; // N - ball count, H - height, W - width
int map[MAX_H][MAX_W]; 
int dx[4] = { -1, 1, 0, 0, }; // ¡è¡é¡ç¡æ
int dy[4] = { 0, 0, -1, 1 };

// return min value
int min(int a, int b){
	return a > b ? b : a;
}
// return non-zero count
int count(){
	int cnt = 0;

	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			if (map[i][j] != 0)
				++cnt;

	return cnt;
}
// copy source array to target
void copy_map(int(*source)[MAX_W], int(*target)[MAX_W]){
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			target[i][j] = source[i][j];
}
// check indexs are accessible
bool inRange(int row, int col){
	if (row > -1 && row < H && col > -1 && col < W)
		return true;
	return false;
}
// map refresh after destroy
void map_refresh(){
	int vector[MAX_H];
	int index;

	for (int i = 0; i < W; ++i){
		index = 0;
		// find non-zero index
		for (int j = H - 1; j > -1; --j){
			if (map[j][i] != 0){
				vector[index++] = map[j][i];
				map[j][i] = 0;
			}
		}
		// copy non-zero data desc
		for (int j = 0; j < index; ++j)
			map[(H - 1) - j][i] = vector[j];
	}	
}
// destory cascade
void destory(int row, int col){
	int cur_num = map[row][col];
	map[row][col] = 0;

	for (int i = 1; i < cur_num; ++i)
		for (int j = 0; j < 4; ++j){
			// next target location
			int n_row = row + dx[j] * i;
			int n_col = col + dy[j] * i;

			// check is possible to destory
			if (inRange(n_row, n_col) && map[n_row][n_col] != 0){
				// destory cascade
				destory(n_row, n_col);
			}
		}
}
// A ball hit the first non-zero element(height) of index(width)
void hit(int index){
	int cur_height = -1;

	// find first hit index
	for (int i = 0; i < H; ++i)
		if (map[i][index] != 0){
			cur_height = i;
			break;
		}

	// destory
	if (cur_height != -1){
		destory(cur_height, index);
		map_refresh();
	}
}

int solveByDFS(int cnt){
	int min_val = MAX_H * MAX_W;

	if (cnt == N)
		return count();	

	for (int i = 0; i < W; ++i){
		int temp_map[MAX_H][MAX_W];
		// copy map temporarily
		copy_map(map, temp_map);

		// current index include
		hit(i);
		min_val = min(min_val, solveByDFS(cnt + 1));

		// recover map
		copy_map(temp_map, map);		
	}

	return min_val;
}

int main(){
	int T, test_case;
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case){
		
		scanf("%d %d %d", &N, &W, &H);

		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j)
				scanf("%d", &map[i][j]);

		printf("#%d %d\n", test_case, solveByDFS(0));
	}

	return 0;
}