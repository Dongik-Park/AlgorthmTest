package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class swexpert_4301 {

	static int[][] map = new int[1002][1002];
	static int dx[] = { 2, 0 };
	static int dy[] = { 0, 2 };
	private static int N;
	private static int M;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; ++tc) {
			// data input
			String s[] = br.readLine().split(" ");
			N = Integer.parseInt(s[1]);
			M = Integer.parseInt(s[0]);
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					map[i][j] = 0;
			// solve
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (map[i][j] == -1)
						continue;
					if (map[i][j] == 0) { // -1이 아닌 부분에 대해 우, 하측 2의 거리에 있는 map을 -1로 초기화한다.
						for(int k = 0; k < dx.length; ++k) {
							int ni = i + dx[k];
							int nj = j + dy[k];
							map[ni][nj] = -1;
						}
					}
				}
			}
			// -1인 위치를 찾는다.
			int cnt = 0;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (map[i][j] == -1)
						++cnt;
				}
			}

			// data output
			StringBuilder builder = new StringBuilder();
			builder.append("#").append(tc).append(" ").append((N * M - cnt) + "");
			System.out.println(builder.toString());
		} // end of test case

		br.close();
	} // end of main

}
