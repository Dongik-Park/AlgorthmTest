#include<cstdio>
#include<queue>
#define MAX_N 50
#define MAX_K 300
#define MAX_SIZE (MAX_N + MAX_K * 2)
using namespace std;

struct Cell{
	int row;
	int col;
	int weight; // 세포 생명력
	int life; // 세포가 활성화되는 시간
};

int N, M, K; // 초기 상태에서줄기 세포가 분포된 세로 크기 N, 가로 크기 M, 배양 시간 K
int map[MAX_SIZE + 1][MAX_SIZE + 1]; // 줄기 세포 맵
int temp_map[MAX_SIZE + 1][MAX_SIZE + 1]; // 줄기 세포 맵
int dx[4] = { 1, -1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1, 1 }; // 상하좌우
queue<Cell> deact_cells; // 비활성화 세포 큐
queue<Cell> act_cells; // 활성화 세포큐

bool inRange(int row, int col){
	if (row >= 0 && row <= MAX_SIZE && col >= 0 && col <= MAX_SIZE)
		return true;
	return false;
}
// 맵 초기화 및 변수 초기화
void init(){
	for (int i = 0; i <= MAX_SIZE; ++i)
		for (int j = 0; j <= MAX_SIZE; ++j)
			map[i][j] = 0;
	while (!deact_cells.empty()) deact_cells.pop();
	while (!act_cells.empty()) act_cells.pop();
}
void deactivateCheck(){
	// 비활성화 상태 갱신
	int size = deact_cells.size();
	for (int i = 0; i < size; ++i){
		Cell cur_cell = deact_cells.front(); deact_cells.pop();
		// 활성화되는 세포에 대해 활성세포 큐에 추가
		if (map[cur_cell.row][cur_cell.col] == 1){
			cur_cell.life = cur_cell.weight; 
			act_cells.push(cur_cell);
			map[cur_cell.row][cur_cell.col] = -1;
		}
		// 생명력이 남은 경우 생명력 1감소 및 비활성화 큐에 재추가
		else if(map[cur_cell.row][cur_cell.col] > 1){
			--map[cur_cell.row][cur_cell.col];
			deact_cells.push(cur_cell);
		}
	}
}
vector<Cell> activateCheck(){
	// 중복 좌표 세포를 포함하는 temp list
	vector<Cell> temp_list;
	int size = act_cells.size();
	for (int i = 0; i < size; ++i){
		Cell cur_cell = act_cells.front(); act_cells.pop();
		// 세포 활성화시간이 다할때까지 큐에 유지시킨다.
		if (--cur_cell.life > 0)
			act_cells.push(cur_cell);
		// 상하좌우에 대해 번식 여부 확인
		for (int j = 0; j < 4; ++j){
			int n_row = cur_cell.row + dx[j];
			int n_col = cur_cell.col + dy[j];
			// 접근가능한 좌표이면서 map에 접근가능할 경우 비활성화 세포 큐 후보 목록에 추가
			if (inRange(n_row, n_col) && map[n_row][n_col] == 0){
				Cell new_cell;
				new_cell.row = n_row;
				new_cell.col = n_col;
				new_cell.weight = cur_cell.weight;
				temp_list.push_back(new_cell);
				++temp_map[n_row][n_col];
			}
		}
	}
	// 중복되는 세포가 존재할 경우 가장 생명력 큰 값만 추출하여 deactive_list에 추가한다.
	vector<Cell> deactivate_list;
	for (int i = 0; i < temp_list.size(); ++i){
		Cell cur_cell = temp_list[i];
		// 중복되는 셀이 존재할 경우
		if (temp_map[cur_cell.row][cur_cell.col] > 1){
			Cell max_cell = cur_cell;
			for (int j = 0; j < temp_list.size(); ++j){
				if (max_cell.weight < temp_list[j].weight &&
					max_cell.row == temp_list[j].row &&
					max_cell.col == temp_list[j].col)
						max_cell = temp_list[j];
			}
			temp_map[max_cell.row][max_cell.col] = 0;
			deactivate_list.push_back(max_cell);
		}
		else if (temp_map[cur_cell.row][cur_cell.col] == 1)
			deactivate_list.push_back(cur_cell);
	}
	return deactivate_list;
}

int solve(){
	int cnt = 0;
	while (++cnt <= K){
		// 활성화 세포 체크 및 비활성화할 목록 반환
		vector<Cell> deactivate_list = activateCheck();
		// 비활성화 세포 체크 
		deactivateCheck();
		// 비활성화할 리스트 큐에 추가
		for (int i = 0; i < deactivate_list.size(); ++i){
			Cell cur_cell = deactivate_list[i];
			map[cur_cell.row][cur_cell.col] = cur_cell.weight;
			temp_map[cur_cell.row][cur_cell.col] = 0;
			deact_cells.push(cur_cell);
		}
	}
	// 현재 큐에 존재하는 데이터 반환
	return deact_cells.size() + act_cells.size();
}

int main(){
	int T, test_case;
	scanf("%d", &T);
	setbuf(stdout, NULL);

	for (test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d %d", &N, &M, &K);
		N += MAX_K;
		M += MAX_K;
		// 맵 및 벡터 초기화
		init();
		// 비활성화 상태 줄기세포 목록 입력
		for (int i = MAX_K; i < N; ++i)
			for (int j = MAX_K; j < M; ++j){
				int weight;
				scanf("%d", &weight);
				Cell cell;
				if(weight != 0){
					cell.row = i;
					cell.col = j;
					cell.weight = weight;
					// 비활성화 큐에 추가 및 맵에 표시
					deact_cells.push(cell);
					map[i][j] = weight;
				}
			}
		// 결과 출력
		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}