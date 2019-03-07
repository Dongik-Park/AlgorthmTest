package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class swexpert_1861 {
	static int N;
	static int[][] map;
	static int[][] dp;

	public static int dfs(int row, int col) {
		if (dp[row][col] != 0) {
			return dp[row][col];
		} else { // 상하좌우에서 이동 가능할 경우 dfs로 찾는다.
			int tempOut = 1;
			int currentValue = map[row][col];
			if (row - 1 >= 0 && currentValue + 1 == map[row - 1][col]) {
				tempOut = Math.max(tempOut, dfs(row - 1, col) + 1);
			}
			if (row + 1 < N && currentValue + 1 == map[row + 1][col]) {
				tempOut = Math.max(tempOut, dfs(row + 1, col) + 1);
			}
			if (col - 1 >= 0 && currentValue + 1 == map[row][col - 1]) {
				tempOut = Math.max(tempOut, dfs(row, col - 1) + 1);
			}
			if (col + 1 < N && currentValue + 1 == map[row][col + 1]) {
				tempOut = Math.max(tempOut, dfs(row, col + 1) + 1);
			}
			dp[row][col] = tempOut;
			return dp[row][col];
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; ++tc) {
			N = Integer.parseInt(br.readLine());
			map = new int[N][N];
			dp = new int[N][N];

			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			// 1. 이동가능 경로 중 가장 긴 경로 찾는다.
			int maxValue = Integer.MIN_VALUE;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					maxValue = Math.max(maxValue, dfs(i, j));
				}
			}
			// 2. 가장 긴 경로 중 가장 작은 수를 찾는다.
			int out = Integer.MAX_VALUE;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (dp[i][j] == maxValue) {
						out = Math.min(out, map[i][j]);
					}
				}
			}
			bw.write("#" + tc + " " + out + " " + maxValue + "\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}

}