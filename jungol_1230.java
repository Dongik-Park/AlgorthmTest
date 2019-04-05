package com.ssafy.algo;

import java.util.Scanner;

public class jungol_1230 {
	private static int N;
	private static int[][] map;
	private static boolean[][] visited;
	private static int res;
	private static final int[] dx = { 1, 0, 0, -1 };
	private static final int[] dy = { 0, 1, -1, 0 };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		map = new int[N][N];
		visited = new boolean[N][N];

		// data input
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				map[i][j] = sc.nextInt();

		// solve
		visited[0][0] = true;
		solve(0, 0, 0);

		// data output
		System.out.println(res);
	}

	private static void solve(int i, int j, int cnt) {
		if (map[i][j] == 2)
			cnt++;
		if (i == N - 1 && j == N - 1) {
			res = res < cnt ? cnt : res;
			return;
		}
		// 현재 좌표에서 4방향을 검사하여 가능한 경우에 대해 dfs로 진행
		for (int dir = 0; dir < dx.length; ++dir) {
			int ni = i + dx[dir];
			int nj = j + dy[dir];
			if (ni < 0 || nj < 0 || ni >= N || nj >= N || visited[ni][nj] || map[ni][nj] == 1)
				continue;
			visited[ni][nj] = true;
			solve(ni, nj, cnt);
			visited[ni][nj] = false;
		}
		
	}

}
