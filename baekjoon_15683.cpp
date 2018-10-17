#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX_N 8
using namespace std;
struct CCTV{
	int row;
	int col;
	int num;
};
int map[MAX_N][MAX_N];
int N, M;
vector<CCTV> cctvs;
vector<int> dirs;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
// copy source map to target
void copyMap(int (*source)[MAX_N], int (*target)[MAX_N]){
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			target[i][j] = source[i][j];
}
// check up
void up(int idx){
	for (int i = cctvs[idx].row - 1; i > -1; --i) if (map[i][cctvs[idx].col] == 6) break; else map[i][cctvs[idx].col] = -1;
}
// check down
void down(int idx){
	for (int i = cctvs[idx].row + 1; i < N; ++i)  if (map[i][cctvs[idx].col] == 6)  break; else map[i][cctvs[idx].col] = -1;
}
// check left
void left(int idx){
	for (int i = cctvs[idx].col - 1; i > -1; --i) if (map[cctvs[idx].row][i] == 6) break; else map[cctvs[idx].row][i] = -1;
}
// check right
void right(int idx){
	for (int i = cctvs[idx].col + 1; i < M; ++i)  if (map[cctvs[idx].row][i] == 6) break; else map[cctvs[idx].row][i] = -1;
}
// marking the decided direction
void monitor(int idx, int dir){
	switch (cctvs[idx].num)
	{
	case 1: 
		if (dir == 0)       up(idx);
		else if (dir == 1)  down(idx);
		else if (dir == 2)  left(idx);
		else if (dir == 3)  right(idx);
		break;
	case 2:
		if (dir == 0 || dir == 1) { up(idx); down(idx); }
		else                      { left(idx); right(idx); }
		break;
	case 3:
		if (dir == 0)       { up(idx); right(idx);  }
		else if (dir == 1)  { down(idx); left(idx); }
		else if (dir == 2)  { left(idx); up(idx);	}
		else if (dir == 3)  { right(idx); down(idx);}
		break;
	case 4:
		if (dir == 0)       { up(idx); right(idx); left(idx);  }
		else if (dir == 1)  { down(idx); left(idx); right(idx);}
		else if (dir == 2)  { left(idx); up(idx); down(idx);   }
		else if (dir == 3)  { right(idx); down(idx); up(idx);  }
		break;
	default:
		up(idx); down(idx); left(idx); right(idx);
		break;
	}
}
// counting
int calc(){
	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (map[i][j] == 0) ++cnt;
	return cnt;
}
// check directions
int dfs(int idx){ 
	if (idx == cctvs.size()) return calc();

	int min_val = N * M;
	int temp_map[MAX_N][MAX_N];
	copyMap(map, temp_map); // copy current state map to temp_map

	if (cctvs[idx].num == 5){
		monitor(idx, 0);
		min_val = min(min_val, dfs(idx + 1));
		copyMap(temp_map, map); // recover
	}
	else{
		if (cctvs[idx].num != 2)
			for (int i = 0; i < 4; ++i){
				monitor(idx, i);
				min_val = min(min_val, dfs(idx + 1));
				copyMap(temp_map, map); // recover
			}
		else
			for (int i = 1; i < 3; ++i){
				monitor(idx, i);
				min_val = min(min_val, dfs(idx + 1));
				copyMap(temp_map, map); // recover
			}
	}

	return min_val;
}
int solve(){
	return dfs(0);
}

int main(){

	cin >> N >> M;
	while (!cctvs.empty()) cctvs.pop_back();

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j){
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5){
				CCTV cctv;
				cctv.row = i; cctv.col = j; cctv.num = map[i][j];
				cctvs.push_back(cctv);
			}
		}

	cout <<  solve() <<endl;

	return 0;
}