#include <iostream>
#include <queue>
#define MAX_N 20
using namespace std;

struct Fish {
	int r;
	int c;
	int size;
};

int map[MAX_N][MAX_N];
int N;
int M;
int r, c;
int fsize = 2;
int eat_cnt;
Fish fishes[MAX_N * MAX_N];
Fish next_fishes[MAX_N * MAX_N];
Fish target;

int dx[4] = {-1,0,1,0};
int dy[4] = { 0,-1,0,1 };
queue<pair<int, int> > que;
bool isMoved = false;
/*
	1�ð� 45������ ������
	bfs���� �����Ѵ�.
	1. ���ʿ� �����¿�� �̵��� ������ - move�Լ� �̿��ؼ�
	2. 0�� �ƴ� ��쿡 ���Ͽ� fishes���� fish�� ã�� ���� ũ�⺸�� ������ ���θ� �Ǻ��Ѵ�. - �̷��� ���� ����� ����⸦ �˾Ƽ� ã�ư���.
		2-1. ���� ��쿡 ���� queue�� clear�ϰ� ��ǥ�� �����Ѵ�.
		2-2. �ƴ� ��쿡 ���� move�� ��� ȣ���Ѵ�.
*/
bool isNext(int r, int c) {
	for (int i = 0; i < M; ++i)
		if (fishes[i].r == r && fishes[i].c == c && map[r][c] != 0 && map[r][c]  < fsize)
			return true;
	return false;
}
bool findNext() {
	int nM = -1;

	cout << endl;
	for (int i = 0; i < M; ++i)
		cout << fishes[i].r << ", " << fishes[i].c << " - " << fishes[i].size << endl;
	cout << endl;

	// ���� ��� ���� ����� ��� ����
	for (int i = 0; i < M; ++i)
		if (map[fishes[i].r][fishes[i].c] != 0 && fishes[i].size < fsize)
			next_fishes[++nM] = fishes[i];

	// ���� ����
	if (nM == -1)
		return false;
	
	// ���� �� �ִ� ����Ⱑ 1�������, �� ����⸦ ������ ����.
	if (nM == 0) {
		target = next_fishes[0];
		return true;
	}

	// ��� ���� ����� 1�� ����
	target = next_fishes[0];
	// ���� �� �ִ� ����Ⱑ 1�������� ���ٸ�, �Ÿ��� ���� ����� ����⸦ ������ ����. 
	int min_val = abs(r - target.r) + abs(c - target.c);
	for (int i = 1; i <= nM; ++i) 
		if(min_val > abs(r - next_fishes[i].r) + abs(c - next_fishes[i].c))
		//if (target.c > next_fishes[i].c) 
			target = next_fishes[i];
	
	// �ش� ����⸦ ���� ��Ͽ��� ����
	for (int i = 0; i < M; ++i)
		if (fishes[i].r == target.r && fishes[i].c == target.c)
			fishes[i].size = 0;

	cout << "(target.r,target.c) = (" << target.r << "," << target.c << ")" << endl;
	return true;
}
bool findNext2() {
	for (int i = 0; i < M; ++i)
		if (map[fishes[i].r][fishes[i].c] != 0) return true;
	return false;
}
void move2(int *cnt) {
	int loop = que.size();
	if (loop == 0) return;

	++*cnt;

	while (loop--) {
		pair<int, int> t = que.front(); que.pop();
		cout << *cnt - 1 << "�� : (" << t.first << "," << t.second << ") fsize : " << fsize << ", eat_cnt : " << eat_cnt << endl;
		for (int i = 0; i < 4; ++i) {
			int nr = t.first + dx[i];
			int nc = t.second + dy[i];
			// ���� ������� ���� ����⸦ ã�� ���
			if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
				// ���� ��ġ�� ������̰� �̵������� ����� ��ġ�� ���
				if (map[nr][nc] != 0 && isNext(nr, nc)) { 
					++eat_cnt; // ���� ī��Ʈ ����
					map[nr][nc] = 0; // �� �ʱ�ȭ
					if (eat_cnt == fsize) { // ���� ī��Ʈ�� ������ ��ġ �� ������ ����
						fsize++;
						eat_cnt = 0;
					}
					r = nr; // �̵� ��� ����
					c = nc;
					// queue�� ������ ���� ����
					while (que.size()) que.pop();
					isMoved = true;
					return;
				}
				// 0�̰ų� �ڱ� �ڽŰ� ��ġ�ϴ� �������� ��ǥ�� ��� 
				else if (map[nr][nc] == 0 || map[nr][nc] == fsize) {
					que.push(make_pair(nr, nc));
				}
			}
		}
	}

	return;
}
bool move(int *cnt) {
	int loop = que.size();
	if (!loop) return false;

	++*cnt;

	while (loop--) {
		pair<int, int> t = que.front(); que.pop();
		cout << *cnt - 1<< "�� : (" << t.first << "," << t.second << ") fsize : " << fsize << ", eat_cnt : " << eat_cnt << endl;
		for (int i = 0; i < 4; ++i) {
			int nr = t.first + dx[i];
			int nc = t.second + dy[i];
			if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
				if (map[nr][nc] == target.size) {
					r = nr;
					c = nc;
					if (++eat_cnt == fsize) {
						fsize++;
						eat_cnt = 0;
						map[nr][nc] = 0;
					}
					cout << *cnt - 1 << "��(����) : (" << nr << "," << nc << ") fsize : " << fsize << ", eat_cnt : " << eat_cnt << endl;
					// queue�� ������ ���� ����
					while (que.size()) que.pop();
					return true;
				}
				else if(map[nr][nc] <= fsize){
					que.push(make_pair(nr, nc));
				}
			}
		}
	}
	return move(cnt);
}
int solve() {
	//�ʱⰪ ����
	int cnt = 0;
	que.push(make_pair(r, c));

	// ���� �̵��� ����Ⱑ ���� ������ �ݺ�
	while (findNext2()) {
		move2(&cnt);
		if (isMoved) { // ����� ��ġ�� ã�� ��쿡�� ť�� ������ġ �߰�
			que.push(make_pair(r, c));
			isMoved = false;
		}
	}
		
	return cnt;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				r = i;
				c = j;
				map[i][j] = 0; // �ʱ� �Ʊ��� ��ġ 0���� ����
			}
			else if (map[i][j] > 0 && map[i][j] < 7) {
				Fish fish;
				fish.r = i;
				fish.c = j;
				fish.size = map[i][j];
				fishes[M++] = fish;
			}
		}

	cout << solve();

	return 0;
}