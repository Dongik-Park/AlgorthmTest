package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swexpert_4613 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		
		for (int testcase = 1; testcase <= T; testcase++) {
			// data input
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int[][] color = new int[N][3]; // W, B, R
			for (int i = 0; i < N; ++i) {
				String s = br.readLine().trim();
				for (int j = 0; j < M; j++) {
					switch (s.charAt(j)) {
					case 'W':
						color[i][0]++;
						break;
					case 'B':
						color[i][1]++;
						break;
					case 'R':
						color[i][2]++;
						break;
					}
				}
			}
			// solve
			int res = N * M;
			for (int cur = 1; cur <= N - 2; cur++) {
				for (int b = 1; b <= N - 1 - cur; b++) {
					int sum = 0;
					for (int i = 0; i < cur; ++i) 
						sum += (M - color[i][0]);
					for (int i = cur; i < cur + b; ++i) 
						sum += (M - color[i][1]);
					for (int i = cur + b; i < N; ++i) 
						sum += (M - color[i][2]);
					// 결과 갱신
					res = Math.min(res, sum);
				}
			}
			// data output
			System.out.println("#" + testcase + " " + res);
		}
	}
}
