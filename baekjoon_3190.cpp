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
	// ���� �ʱ� ��ġ ���ä�
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
		map[r][c] = 2; // ��� ǥ��
	}
	int moveCnt;
	cin >> moveCnt;
	for (int i = 0; i < moveCnt; ++i){
		int count;
		char dir;
		cin >> count >> dir;
		// 1. ���� ��ġ ���� �������� count��ŭ �̵��Ѵ�.
		int loop = count - res;
		for (int j = 0; j < loop; ++j){ 
			Snake head = snake.front();
			Snake tail = snake.back();
			int nr = head.r + dx[head.dir];
			int nc = head.c + dy[head.dir];

			++res; // �ð��� ����
			if (nr < 1 || nc < 1 || nr > N || nc > N || map[nr][nc] == 1){ // ���̳� �ڽ��� ���� �ε��� ���
				cout << res; // ���� ����
				return 0;
			}
			if (map[nr][nc] == 2){ // ����� ���� ���
				map[nr][nc] = 0;
			}
			else{ // ����� ���� ���
				map[snake.back().r][snake.back().c] = 0; // ���� ����
				snake.pop_back(); // ���� 1 ����
			}
			// �Ӹ� ���� 1����
			Snake news;
			news.r = nr;
			news.c = nc;
			news.dir = head.dir;
			snake.push_front(news);
			map[nr][nc] = 1;
		}
		// 2. ���� ��ȯ�Ѵ�.
		int curd = snake.front().dir;
		if (dir == 'L'){ // �������� 90�� ���
			snake.front().dir = (curd + 1) % 4;
		}
		else{ // ���������� 90�� ���
			snake.front().dir = (curd + 3) % 4;
		}
	}
	while (true){
		Snake head = snake.front();
		Snake tail = snake.back();
		int nr = head.r + dx[head.dir];
		int nc = head.c + dy[head.dir];
		++res; // �ð��� ����

		if (nr < 1 || nc < 1 || nr > N || nc > N || map[nr][nc] == 1){ // ���̳� �ڽ��� ���� �ε��� ���
			cout << res; // ���� ����
			break;
		}
		if (map[nr][nc] == 2){ // ����� ���� ���
			map[nr][nc] = 0;
		}
		else{ // ����� ���� ���
			map[snake.back().r][snake.back().c] = 0; // ���� ����
			snake.pop_back(); // ���� 1 ����
		}
		// �Ӹ� ���� 1����
		Snake news;
		news.r = nr;
		news.c = nc;
		news.dir = head.dir;
		snake.push_front(news);
		map[nr][nc] = 1;
	}

	return 0;
}