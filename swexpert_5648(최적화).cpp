#include<cstdio>
#include<vector>
#define MAX_N 1000
using namespace std;
struct Atom{
	int x;
	int y;
	int dir;
	int energy;
};
int N; // 원자 개수
Atom atoms[MAX_N]; // 원자 목록
bool alive[MAX_N]; // 원자 생사여부
int map[2 * MAX_N + 1][2 * MAX_N + 1]; // 원자 이동 맵
int dx[4] = { 1, 0, -1, 0 }; // 상 좌 하 우
int dy[4] = { 0, -1, 0, 1 };
bool inRange(int row, int col){
	if (row > -1 && row < 2 * MAX_N + 1 && col > -1 && col < 2 * MAX_N + 1) return true;
	return false;
}
void check(){
	// 중복되는 구간 확인 위해 맵 cnt 표시
	for (int i = 0; i < N; ++i)
		if (alive[i]) ++map[atoms[i].x][atoms[i].y];

	// 1. cnt > 1 - 원자 충돌 조건
	for (int i = 0; i < N; ++i)
		if (alive[i] && map[atoms[i].x][atoms[i].y] > 1){
			for (int j = i + 1; j < N; ++j) // 동일한 위치의 원자 찾아 소멸
				if (alive[j] && atoms[i].x == atoms[j].x && atoms[i].y == atoms[j].y){
					--map[atoms[j].x][atoms[j].y];
					alive[j] = false;
				}
			--map[atoms[i].x][atoms[i].y];
			alive[i] = false;
		}	

	// 2. 다음 이동 방향에 원자 존재하는지 확인
	for (int i = 0; i < N; ++i){
		if (!alive[i]) continue;
		// 다음 이동할 좌표
		int nx = atoms[i].x + dx[atoms[i].dir];
		int ny = atoms[i].y + dy[atoms[i].dir];
		if (inRange(nx, ny) && map[nx][ny] > 0){
			for (int j = 0; j < N; ++j){ // 원자가 존재하는 경우 해당 원자를 찾아 방향이 현재와 반대인지 확인
				if (alive[j] && atoms[j].x == nx && atoms[j].y == ny && (atoms[j].dir + 2 % 4) == atoms[i].dir){
					--map[atoms[i].x][atoms[i].y];
					--map[atoms[j].x][atoms[j].y];
					alive[i] = false;
					alive[j] = false;
					break;
				}
			}
		}
	}

	// 맵 cnt 복구
	for (int i = 0; i < N; ++i)
		if(alive[i]) --map[atoms[i].x][atoms[i].y];
}
bool isFinished(){ // 종료 조건 : 모든 원자들이 비활성화 되었을 경우
	for (int i = 0; i < N; ++i)
		if (alive[i]) return false;
	return true;
}
int solve(){
	// 처음 위치 확인
	check();
	while (!isFinished()){
		// 각 원자 좌표 갱신
		for (int i = 0; i < N; ++i){
			if (!alive[i]) continue;
			atoms[i].x = atoms[i].x + dx[atoms[i].dir];
			atoms[i].y = atoms[i].y + dy[atoms[i].dir];
			// 끝까지 같을 경우 에너지 0으로 초기화 및 소멸
			if (!inRange(atoms[i].x, atoms[i].y)) {
				alive[i] = false;
				atoms[i].energy = 0;
			}
		}
		// 갱신된 좌표를 기준으로 확인
		check();
	}
	// 충돌한 에너지들의 합 계산
	int sum = 0;
	for (int i = 0; i < N; ++i) sum += atoms[i].energy;
	return sum;
}
int main(){

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc){
		scanf("%d", &N);

		for (int i = 0; i < N; ++i){
			Atom atom;
			scanf("%d %d %d %d", &atom.y, &atom.x, &atom.dir, &atom.energy);
			atom.x += MAX_N;
			atom.y += MAX_N;
			if (atom.dir == 1) atom.dir = 2;
			else if (atom.dir == 2) atom.dir = 1;
			atoms[i] = atom;
			alive[i] = true;
		}

		printf("#%d %d\n", tc, solve());
	}

	return 0;
}