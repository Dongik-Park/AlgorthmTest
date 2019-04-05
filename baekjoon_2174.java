package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class baekjoon_2174 {
	static final int dx[] = { -1, 0, 1, 0 };
	static final int dy[] = { 0, -1, 0, 1 };
	static int [][]occupied = new int[101][101];
	static class Robot {
		int x;
		int y;
		int dir;
		public Robot(int x, int y, int dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// data input
		StringTokenizer st = new StringTokenizer(br.readLine());
		final int COL = Integer.parseInt(st.nextToken());
		final int ROW = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		Robot[] robots = new Robot[N + 1];
		
		for(int i = 1 ; i <= N; ++i) {
			st = new StringTokenizer(br.readLine());
			int col = Integer.parseInt(st.nextToken());
			int row = Integer.parseInt(st.nextToken());
			char dir = st.nextToken().charAt(0);
			if(dir == 'N') // ��ǥ�� �����̹Ƿ� ���ϸ� �ݴ�� ����
				robots[i] = new Robot(row, col, 2);
			else if(dir == 'W')
				robots[i] = new Robot(row, col, 1);
			else if(dir == 'S')
				robots[i] = new Robot(row, col, 0);
			else if(dir == 'E')
				robots[i] = new Robot(row, col, 3);
			occupied[row][col] = i;
		}
		
		// solve
		for(int i = 0; i < M; ++i) {
			st = new StringTokenizer(br.readLine());
			int rNum = Integer.parseInt(st.nextToken()); // �̵� �κ� ��ȣ
			char dirChar = st.nextToken().charAt(0); // ����
			int loop = Integer.parseInt(st.nextToken()); // �ݺ�Ƚ��
			
			Robot cur = robots[rNum]; // �̵��� �κ�
			for(int j = 0; j < loop; ++j) {
				if(dirChar == 'L') {
					cur.dir = (cur.dir + 3) % 4; // �̵� ���� ���� �ݽð�� 90��
				}
				else if(dirChar == 'R') {
					cur.dir = (cur.dir + 1) % 4; // �̵� ���� ���� �ð�� 90��
				}
				else {
					occupied[cur.x][cur.y] = 0;
					int nx = cur.x + dx[cur.dir]; // ���ο� ��ǥ
					int ny = cur.y + dy[cur.dir];
					if(nx < 1 || ny < 1 || nx > ROW || ny > COL) {
						System.out.println("Robot " + rNum + " crashes into the wall");
						return;
					}
					else if(occupied[nx][ny] > 0) {
						System.out.println("Robot " + rNum + " crashes into robot " + occupied[nx][ny]);
						return;
					}
					occupied[nx][ny] = rNum;
					cur.x = nx;
					cur.y = ny;
				}
			}
			
		}
		System.out.println("OK");
	}
}
