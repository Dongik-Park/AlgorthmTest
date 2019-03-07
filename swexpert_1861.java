package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class swexpert_1861 {
	static int N;
	static final int MAX_N = 1000;
	static int map[][] = new int[MAX_N + 1][MAX_N + 1];
	static boolean visited[][] = new boolean[MAX_N + 1][MAX_N + 1];
	static int dx[] = { -1, 1, 0, 0 };
	static int dy[] = { 0, 0, -1, 1 };

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; ++tc) {
			// data input
			N = Integer.parseInt(br.readLine().trim());
			for (int i = 0; i < N; ++i) {
				String s[] = br.readLine().trim().split(" ");
				for (int j = 0; j < N; ++j) {
					map[i][j] = Integer.parseInt(s[j]);
					visited[i][j] = false;
				}
			}
			// solve
			int res[] = solve();
			// data output
			bw.write("#" + tc + " " + res[0] + " " + res[1] + "\n");
		}

		bw.flush();
		bw.close();
		br.close();
	}

	private static int[] solve() {
		int res[] = {N * N, 0};
		for (int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				for(int dir = 0; dir < dx.length; ++dir) {
					int nr = i + dx[dir];
					int nc = j + dy[dir];
					if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] ||map[nr][nc] - map[i][j] != 1) 
						continue;
					visited[i][j] = true;
					int cur = dfs(nr, nc, 1);
					if(res[1] < cur) { // 이동 횟수가 많은 경우
						res[0] = map[i][j];
						res[1] = cur;
					}
					else if(res[1] == cur && map[i][j] < res[0]) { // 이동 횟수가 현재값이랑 같고 방번호가 작을 경우
						res[0] = map[i][j];
					}
					visited[i][j] = false;
				}
			}
		}
		return res;
	}

	private static int dfs(int i, int j, int res) {
		++res;
		for(int dir = 0; dir < dx.length; ++dir) {
			int nr = i + dx[dir];
			int nc = j + dy[dir];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || map[nr][nc] - map[i][j] != 1) 
				continue;
			visited[i][j] = true;
			res = dfs(nr, nc, res);
			visited[i][j] = false;
		}
		return res;
	}
}
