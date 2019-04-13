#include<iostream>
#include<list>
#define MAX_N 100
using namespace std;
int map[MAX_N + 1][MAX_N + 1];
int N;
int res;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
struct Snake{
	int r;
	int c;
	int dir;
};
list<Snake> snake;
int main(){
	cin >> N;
	// 뱀위 초기 위치 세팅ㄴ
	Snake inits;
	inits.r = 1;
	inits.c = 1;
	inits.dir = 3;
	snake.push_back(inits);
	map[1][1] = 1;

	int appleCnt;
	cin >> appleCnt;
	for (int i = 0; i < appleCnt; ++i){
		int r, c;
		cin >> r >> c;
		map[r][c] = 2; // 사과 표시
	}
	int moveCnt;
	cin >> moveCnt;
	for (int i = 0; i < moveCnt; ++i){
		int count;
		char dir;
		cin >> count >> dir;
		// 1. 현재 위치 현재 방향으로 count만큼 이동한다.
		int loop = count - res;
		for (int j = 0; j < loop; ++j){ 
			Snake head = snake.front();
			Snake tail = snake.back();
			int nr = head.r + dx[head.dir];
			int nc = head.c + dy[head.dir];

			++res; // 시간초 증가
			if (nr < 1 || nc < 1 || nr > N || nc > N || map[nr][nc] == 1){ // 벽이나 자신의 몸과 부딪힐 경우
				cout << res; // 종료 조건
				return 0;
			}
			if (map[nr][nc] == 2){ // 사과가 있을 경우
				map[nr][nc] = 0;
			}
			else{ // 사과가 없을 경우
				map[snake.back().r][snake.back().c] = 0; // 꼬리 삭제
				snake.pop_back(); // 꼬리 1 삭제
			}
			// 머리 길이 1증가
			Snake news;
			news.r = nr;
			news.c = nc;
			news.dir = head.dir;
			snake.push_front(news);
			map[nr][nc] = 1;
		}
		// 2. 방향 전환한다.
		int curd = snake.front().dir;
		if (dir == 'L'){ // 왼쪽으로 90일 경우
			snake.front().dir = (curd + 1) % 4;
		}
		else{ // 오른쪽으로 90일 경우
			snake.front().dir = (curd + 3) % 4;
		}
	}
	while (true){
		Snake head = snake.front();
		Snake tail = snake.back();
		int nr = head.r + dx[head.dir];
		int nc = head.c + dy[head.dir];
		++res; // 시간초 증가

		if (nr < 1 || nc < 1 || nr > N || nc > N || map[nr][nc] == 1){ // 벽이나 자신의 몸과 부딪힐 경우
			cout << res; // 종료 조건
			break;
		}
		if (map[nr][nc] == 2){ // 사과가 있을 경우
			map[nr][nc] = 0;
		}
		else{ // 사과가 없을 경우
			map[snake.back().r][snake.back().c] = 0; // 꼬리 삭제
			snake.pop_back(); // 꼬리 1 삭제
		}
		// 머리 길이 1증가
		Snake news;
		news.r = nr;
		news.c = nc;
		news.dir = head.dir;
		snake.push_front(news);
		map[nr][nc] = 1;
	}

	return 0;
}