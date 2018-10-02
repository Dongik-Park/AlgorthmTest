#include <cstdio>
#include <vector>
#define MAX_N 1000
#define MAX_LOC 1000
#define MIN_LOC -1000
using namespace std;

// 원자 구조체
struct Atom{
	int row;
	int col;
	int energy;
	int dir;
};
// 원자목록
vector<Atom> list;
// 원자 이동 표시할 map
int map[MAX_LOC - (MIN_LOC) + 1][MAX_LOC - (MIN_LOC) + 1];
// 원자 소멸 여부 배열
bool isActive[MAX_N];
// 상, 하, 좌, 우
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
// 배열 index 검사
bool inRange(int row, int col){
	if (row >= 0 && row <= MAX_LOC + MAX_LOC && col >= 0 && col <= MAX_LOC + MAX_LOC)
		return true;
	return false;
}
// 종료 여부 확인
bool isFinished(int N){
	int cnt = 0;
	for (int i = 0; i < N; ++i){
		if (cnt > 1)
			return false;
		if (isActive[i])
			++cnt;
	}
	return true;
}
// map과 원자 소멸 여부 배열 초기화 및 초기값 세팅
void init(int N){
	for (int i = 0; i <= MAX_LOC + MAX_LOC; ++i)
		for (int j = 0; j <= MAX_LOC + MAX_LOC; ++j)
			map[i][j] = 0;
	for (int i = 0; i < N; ++i)
		isActive[i] = true;
	for (int i = 0; i < list.size(); ++i)
		map[list[i].row][list[i].col] = 1;
}
// 만약 인접한 좌표에 원자가 존재할 경우(다음 이동 시 1초미만으로 소멸하는 경우) 인접한 좌표를 추가하고 현재 원자 에너지를 추가 및 소멸시킨다.
void findAdjacent(int * sum){
	for (int i = 0; i < list.size(); ++i){
		if (!isActive[i])
			continue;
		int n_row = list[i].row + dx[list[i].dir];
		int n_col = list[i].col + dy[list[i].dir];
		if (inRange(n_row, n_col) && map[n_row][n_col] > 0){
			for (int j = 0; j < list.size(); ++j){
				if (isActive[j] &&
					list[j].row == n_row &&
					list[j].col == n_col &&
					// 방향 반대 조건 충족할 경우
					(-1 * dx[list[j].dir]) == dx[list[i].dir] &&
					(-1 * dy[list[j].dir]) == dy[list[i].dir]) {
					// 인접한 원자 두개의 에너지 누적
					*sum += list[i].energy;
					*sum += list[j].energy;
					// 각 원자의 index 1 감소 초기화
					--map[list[i].row][list[i].col];
					--map[list[j].row][list[j].col];
					// 각 원자 소멸
					isActive[i] = false;
					isActive[j] = false;
				}
			}
		}
	}
}
// 원자들을 방향에 맞게 1칸씩 이동시킨다.
void moveAtoms(){
	for (int i = 0; i < list.size(); ++i){
		// 현재 원자가 소멸되었을 경우 
		if (!isActive[i])
			continue;
		// 이전 방문 map index 초기화
		--map[list[i].row][list[i].col];
		// list 초기화
		int n_row = list[i].row + dx[list[i].dir];
		int n_col = list[i].col + dy[list[i].dir];
		// 접근 가능한 좌표일 경우
		if (inRange(n_row, n_col)){
			list[i].row = n_row;
			list[i].col = n_col;
			++map[n_row][n_col];
		}
		// 접근 가능 좌표를 벗어났을 경우 소멸
		else
			isActive[i] = false;
	}
}
void checkDuplicate(int *sum){
	// 두개 이상의 원자가 방문한 좌표 목록
	vector<pair<int, int>> cur_list;
	// 두개 이상 방문한 노드를 찾는다.
	for (int i = 0; i < list.size(); ++i)
		if (map[list[i].row][list[i].col] > 1){
			cur_list.push_back(make_pair(list[i].row, list[i].col));
		}
	// 두개 이상 방문한 좌표에 존재하는 원자들에 대해 에너지를 더하고 map을 초기한 뒤 소멸한다. 
	for (int i = 0; i < cur_list.size(); ++i){
		int cur_row = cur_list[i].first;
		int cur_col = cur_list[i].second;
		for (int j = 0; j < list.size(); ++j)
			if (isActive[j] && cur_row == list[j].row && cur_col == list[j].col){
				--map[list[j].row][list[j].col];
				*sum += list[j].energy;
				isActive[j] = false;
			}
	}
}
int solve(int N){
	int sum = 0;
	// 변수 초기화 
	init(N);

	while (!isFinished(N)){
		// 인접한 원자 제거
		findAdjacent(&sum);
		// 원자 이동
		moveAtoms();
		// 중복된 원자 소멸
		checkDuplicate(&sum);
	}

	return sum;
}

int main(){

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		int N;
		scanf("%d", &N);
		// 원자 목록 입력
		while (!list.empty()) list.pop_back();
		for (int i = 0; i < N; ++i){
			Atom atom;
			scanf("%d %d %d %d", &atom.col, &atom.row, &atom.dir, &atom.energy);
			atom.col += MAX_LOC;
			atom.row += MAX_LOC;
			list.push_back(atom);
		}
		// 결과 출력
		printf("#%d %d\n", test_case, solve(N));
	}

	return 0;
}