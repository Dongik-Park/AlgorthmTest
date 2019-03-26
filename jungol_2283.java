package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class jungol_2283 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		// data input
		int N = Integer.parseInt(br.readLine().trim());
		int[][] p = new int[N + 1][3]; // 각 집을 색칠하는 비용
		for (int i = 1; i <= N; ++i) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < 3; ++j) {
				p[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		// solve
		int[][] dp = new int[N + 1][3]; // 0:r, 1:g, 2:b
		for(int i = 1; i <= N; ++i) { // 점화식
			dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + p[i][0]; // i번째 집을 빨강으로 칠하는 경우
			dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + p[i][1]; // i번째 집을 초록으로 칠하는 경우
			dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + p[i][2]; // i번째 집을 파랑으로 칠하는 경우
		}
		
		// dp[N][0],dp[N][1],dp[N][2] 중의 최소값 출력
		int min = Integer.MAX_VALUE;
		for(int i = 0; i < 3; ++i)
			min = Math.min(dp[N][i], min);
		
		// data output
		System.out.println(min);
	} // end of main

} // end of class
