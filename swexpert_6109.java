package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class swexpert_6109 {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; tc++) {
			// data input
			String s[] = br.readLine().trim().split(" ");
			int N = Integer.parseInt(s[0]);
			String dir = s[1];
			int map[][] = new int[N][N];
			for(int i = 0; i < N; ++i) {
				s = br.readLine().split(" ");
				for(int j = 0; j < N; ++j)
					map[i][j] = Integer.parseInt(s[j]);
			}
			// solve
			switch (dir) {
			case "up":
				for(int i = 0; i < N; ++i) {
					Queue<Integer> que = new LinkedList<>();
					for(int j = 0; j < N; ++j) {
						if(map[j][i] != 0)
							que.add(map[j][i]);
						map[j][i] = 0;
					}
					int size = que.size();
					for(int j = 0; j < size && !que.isEmpty(); ++j) {
						map[j][i] = que.poll();
						if(!que.isEmpty() && map[j][i] == que.peek()) {
							map[j][i] += que.poll();
						}
					}
				}
				break;
			case "down":
				for(int i = 0; i < N; ++i) {
					Queue<Integer> que = new LinkedList<>();
					for(int j = N - 1; j >= 0; --j) {
						if(map[j][i] != 0)
							que.add(map[j][i]);
						map[j][i] = 0;
					}
					int size = que.size();
					for(int j = 0; j < size && !que.isEmpty(); ++j) {
						map[N - 1 - j][i] = que.poll();
						if(!que.isEmpty() && map[N - 1 - j][i] == que.peek()) {
							map[N - 1 - j][i] += que.poll();
						}
					}
				}
				break;
			case "left":
				for(int i = 0; i < N; ++i) {
					Queue<Integer> que = new LinkedList<>();
					for(int j = 0; j < N; ++j) {
						if(map[i][j] != 0)
							que.add(map[i][j]);
						map[i][j] = 0;
					}
					int size = que.size();
					for(int j = 0; j < size && !que.isEmpty(); ++j) {
						map[i][j] = que.poll();
						if(!que.isEmpty() && map[i][j] == que.peek()) {
							map[i][j] += que.poll();
						}
					}
				}
				break;
			case "right":
				for(int i = 0; i < N; ++i) {
					Queue<Integer> que = new LinkedList<>();
					for(int j = N - 1; j >= 0; --j) {
						if(map[i][j] != 0)
							que.add(map[i][j]);
						map[i][j] = 0;
					}
					int size = que.size();
					for(int j = 0; j < size && !que.isEmpty(); ++j) {
						map[i][N - 1 - j] = que.poll();
						if(!que.isEmpty() && map[i][N - 1 - j] == que.peek()) {
							map[i][N - 1 - j] += que.poll();
						}
					}
				}
				break;
			}

			// data output
			System.out.println("#" + tc);
			for(int i = 0; i < N; ++i) {
				for(int j = 0; j < N; ++j)
					System.out.print(map[i][j] + " ");
				System.out.println();
			}
		}
	}

}
