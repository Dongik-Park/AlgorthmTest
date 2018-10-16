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
int N; // ���� ����
Atom atoms[MAX_N]; // ���� ���
bool alive[MAX_N]; // ���� ���翩��
int map[2 * MAX_N + 1][2 * MAX_N + 1]; // ���� �̵� ��
int dx[4] = { 1, 0, -1, 0 }; // �� �� �� ��
int dy[4] = { 0, -1, 0, 1 };
bool inRange(int row, int col){
	if (row > -1 && row < 2 * MAX_N + 1 && col > -1 && col < 2 * MAX_N + 1) return true;
	return false;
}
void check(){
	// �ߺ��Ǵ� ���� Ȯ�� ���� �� cnt ǥ��
	for (int i = 0; i < N; ++i)
		if (alive[i]) ++map[atoms[i].x][atoms[i].y];

	// 1. cnt > 1 - ���� �浹 ����
	for (int i = 0; i < N; ++i)
		if (alive[i] && map[atoms[i].x][atoms[i].y] > 1){
			for (int j = i + 1; j < N; ++j) // ������ ��ġ�� ���� ã�� �Ҹ�
				if (alive[j] && atoms[i].x == atoms[j].x && atoms[i].y == atoms[j].y){
					--map[atoms[j].x][atoms[j].y];
					alive[j] = false;
				}
			--map[atoms[i].x][atoms[i].y];
			alive[i] = false;
		}	

	// 2. ���� �̵� ���⿡ ���� �����ϴ��� Ȯ��
	for (int i = 0; i < N; ++i){
		if (!alive[i]) continue;
		// ���� �̵��� ��ǥ
		int nx = atoms[i].x + dx[atoms[i].dir];
		int ny = atoms[i].y + dy[atoms[i].dir];
		if (inRange(nx, ny) && map[nx][ny] > 0){
			for (int j = 0; j < N; ++j){ // ���ڰ� �����ϴ� ��� �ش� ���ڸ� ã�� ������ ����� �ݴ����� Ȯ��
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

	// �� cnt ����
	for (int i = 0; i < N; ++i)
		if(alive[i]) --map[atoms[i].x][atoms[i].y];
}
bool isFinished(){ // ���� ���� : ��� ���ڵ��� ��Ȱ��ȭ �Ǿ��� ���
	for (int i = 0; i < N; ++i)
		if (alive[i]) return false;
	return true;
}
int solve(){
	// ó�� ��ġ Ȯ��
	check();
	while (!isFinished()){
		// �� ���� ��ǥ ����
		for (int i = 0; i < N; ++i){
			if (!alive[i]) continue;
			atoms[i].x = atoms[i].x + dx[atoms[i].dir];
			atoms[i].y = atoms[i].y + dy[atoms[i].dir];
			// ������ ���� ��� ������ 0���� �ʱ�ȭ �� �Ҹ�
			if (!inRange(atoms[i].x, atoms[i].y)) {
				alive[i] = false;
				atoms[i].energy = 0;
			}
		}
		// ���ŵ� ��ǥ�� �������� Ȯ��
		check();
	}
	// �浹�� ���������� �� ���
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