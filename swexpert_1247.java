package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swexpert_1247 {
	static int N;
	static int result;
	static int answer;
	static int x[] = new int[10];
	static int y[] = new int[10];
	static int companyX, companyY;
	static int homeX, homeY;
	static boolean visited[];

	public static void tsp(int cur, int totDistance, int count) {
		visited[cur] = true; // 방문 표시
		
		if(count == 1) {
			totDistance += Math.abs(companyX - x[cur]) + Math.abs(companyY - y[cur]); // 처음의 경우 회사부터 거리 추가
		}
		
		if (count == N) { // 모두 방문하였을 경우
			result = Math.min(totDistance + Math.abs(homeX - x[cur]) + Math.abs(homeY - y[cur]), result);
			visited[cur] = false;
			return;
		}

		for (int i = 0; i < N; i++) {
			int curDistance = Math.abs(x[cur] - x[i]) + Math.abs(y[cur] - y[i]);
			if (!visited[i] && curDistance != 0) { // 방문하지 않고 이어져 있을 경우
				if (totDistance + curDistance < result) { // 최소 거리보다 작을 경우에만 재귀
					tsp(i, totDistance + curDistance, count + 1);
				}
			}
		}
		visited[cur] = false; // 방문 해제
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder build = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; ++tc) {
			// data input & init
			N = Integer.parseInt(br.readLine());
			visited = new boolean[N]; // 방문 체크 배열 생성
			StringTokenizer token = new StringTokenizer(br.readLine());
			companyX = Integer.parseInt(token.nextToken());
			companyY = Integer.parseInt(token.nextToken());
			homeX = Integer.parseInt(token.nextToken());
			homeY = Integer.parseInt(token.nextToken());
			for (int i = 0; i < N; ++i) {
				x[i] = Integer.parseInt(token.nextToken());
				y[i] = Integer.parseInt(token.nextToken());
			}
			result = Integer.MAX_VALUE;

			// solve
			for (int i = 0; i < N; i++) { // 모든 정점 방문 시작
				tsp(i, 0, 1);
			}

			build.append("#" + tc + " " + result + "\n");
		}

		// data output
		System.out.println(build);
	}

}
