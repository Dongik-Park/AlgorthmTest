package com.ssafy.algo;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class swexpert_7250 {
	static final int dx[] = {-1,1,0,0};
	static final int dy[] = {0,0,-1,1};
	static class Scott{
		int x;
		int y;
		int time;
		int cnt;
		public Scott(int x, int y, int time, int cnt) {
			this.x = x;
			this.y = y;
			this.time = time;
			this.cnt = cnt;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine().trim());
		
		for(int tc = 1; tc <= T; ++tc) {
			// data input
			String s[] = br.readLine().trim().split(" ");
			int N = Integer.parseInt(s[0]); 
			int M = Integer.parseInt(s[1]); 
			int K = Integer.parseInt(s[2]); 
			char [][]map = new char[N][M];
			Queue<Scott> sque = new LinkedList<>();
			Queue<Point> vque = new LinkedList<>();
			Queue<Point> fque = new LinkedList<>();
			for(int i = 0; i < N; ++i) {
				String str = br.readLine().trim();
				for(int j = 0; j < M; ++j) {
					map[i][j] = str.charAt(j);
					if(map[i][j] == 'S')
						sque.add(new Scott(i, j, 0, 0));
					else if(map[i][j] == 'V')
						vque.add(new Point(i, j));
					else if(map[i][j] == 'F')
						fque.add(new Point(i, j));
				}
			}
			
			// solve
			boolean isAlive = true;
			boolean scottWin = false;
			int res = Integer.MAX_VALUE; // 스캇의 최단 경로
			while(isAlive && !scottWin) {
				
				// 불이 먼저 번지기 시작한다.
				int size = fque.size();
				for(int i = 0; i < size && isAlive; ++i) {
					Point cur = fque.remove();
					for(int dir = 0; dir < dx.length; ++dir){
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if(nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 'W' || map[nx][ny] == 'X' || map[nx][ny] =='E' )
							continue;
						fque.add(new Point(nx, ny));
						/*if(map[nx][ny] == 'E') {
							isAlive = false;
							break;
						}*/
						map[nx][ny] = 'F';
					}
				}
				
				// 불이 도착지점에 먼저 번진 경우
				/*if(!isAlive) {
					break;
				}*/
				
				// 악당이 다음으로 이동한다.
				size = vque.size();
				for(int i = 0; i < size && isAlive; ++i) {
					Point cur = vque.remove();
					for(int dir = 0; dir < dx.length; ++dir){
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if(nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 'W' || map[nx][ny] == 'X')
							continue;
						if(map[nx][ny] == 'E') {
							isAlive = false;
							break;
						}
						vque.add(new Point(nx, ny));
					}
				}
				
				// 악당이 도착지점에 먼저 도착한 경우
				if(!isAlive) {
					break;
				}
				
				// 스캇이 마지막으로 이동한다.
				size = sque.size();
				for(int i = 0; i < size && !scottWin; ++i) {
					Scott cur = sque.remove();
					for(int dir = 0; dir < dx.length; ++dir){
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if(nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 'X' || map[nx][ny] == 'F')
							continue;
						if(map[nx][ny] == 'W' && cur.time + 1 <= K) {
							sque.add(new Scott(nx, ny, cur.time + 1, cur.cnt + 1));
						}
						else if(map[nx][ny] == 'A')
							sque.add(new Scott(nx, ny, 0, cur.cnt + 1));
						else if(map[nx][ny] == 'E') {
							res = Math.min(res, cur.cnt + 1);
							scottWin = true;
							break;
						}
					}
				}
				
			} // end of while
			
			if(scottWin) {
				System.out.println("#" + tc + " " + res);
			}
			else {
				System.out.println("#" + tc + " -1");
			}
			
		} // end of test case
		
	}// end of main

} // end of class
