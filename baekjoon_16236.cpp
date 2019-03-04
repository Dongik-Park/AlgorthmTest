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
	1시간 45분정도 진행함
	bfs에서 시작한다.
	1. 애초에 상하좌우로 이동해 나가고 - move함수 이용해서
	2. 0이 아닐 경우에 대하여 fishes에서 fish를 찾고 현재 크기보다 작은지 여부를 판별한다. - 이러면 가장 가까운 물고기를 알아서 찾아간다.
		2-1. 맞을 경우에 대해 queue를 clear하고 좌표를 갱신한다.
		2-2. 아닐 경우에 대해 move를 재귀 호출한다.
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

	// 다음 잡아 먹을 물고기 목록 추출
	for (int i = 0; i < M; ++i)
		if (map[fishes[i].r][fishes[i].c] != 0 && fishes[i].size < fsize)
			next_fishes[++nM] = fishes[i];

	// 종료 조건
	if (nM == -1)
		return false;
	
	// 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
	if (nM == 0) {
		target = next_fishes[0];
		return true;
	}

	// 잡아 먹을 물고기 1개 지정
	target = next_fishes[0];
	// 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다. 
	int min_val = abs(r - target.r) + abs(c - target.c);
	for (int i = 1; i <= nM; ++i) 
		if(min_val > abs(r - next_fishes[i].r) + abs(c - next_fishes[i].c))
		//if (target.c > next_fishes[i].c) 
			target = next_fishes[i];
	
	// 해당 물고기를 다음 목록에서 제외
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
		cout << *cnt - 1 << "번 : (" << t.first << "," << t.second << ") fsize : " << fsize << ", eat_cnt : " << eat_cnt << endl;
		for (int i = 0; i < 4; ++i) {
			int nr = t.first + dx[i];
			int nc = t.second + dy[i];
			// 현재 사이즈보다 작은 물고기를 찾은 경우
			if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
				// 현재 위치가 물고기이고 이동가능한 물고기 위치일 경우
				if (map[nr][nc] != 0 && isNext(nr, nc)) { 
					++eat_cnt; // 먹은 카운트 증가
					map[nr][nc] = 0; // 맵 초기화
					if (eat_cnt == fsize) { // 먹은 카운트와 사이즈 일치 시 사이즈 증가
						fsize++;
						eat_cnt = 0;
					}
					r = nr; // 이동 경로 갱신
					c = nc;
					// queue의 데이터 전부 삭제
					while (que.size()) que.pop();
					isMoved = true;
					return;
				}
				// 0이거나 자기 자신과 일치하는 사이즈의 좌표일 경우 
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
		cout << *cnt - 1<< "번 : (" << t.first << "," << t.second << ") fsize : " << fsize << ", eat_cnt : " << eat_cnt << endl;
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
					cout << *cnt - 1 << "번(종료) : (" << nr << "," << nc << ") fsize : " << fsize << ", eat_cnt : " << eat_cnt << endl;
					// queue의 데이터 전부 삭제
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
	//초기값 세팅
	int cnt = 0;
	que.push(make_pair(r, c));

	// 다음 이동할 물고기가 있을 경우까지 반복
	while (findNext2()) {
		move2(&cnt);
		if (isMoved) { // 물고기 위치를 찾은 경우에만 큐에 현재위치 추가
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
				map[i][j] = 0; // 초기 아기상어 위치 0으로 지정
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
