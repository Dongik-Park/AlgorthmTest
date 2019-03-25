package com.ssafy.algo;

import java.util.Scanner;

public class jungol_2462 {

	static final int MAX_N = 501;
	static boolean[][] map = new boolean[MAX_N][MAX_N];
	private static boolean[] chk;
	private static int N;
	private static int M;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// data input
		N = sc.nextInt();
		M = sc.nextInt();
		for (int i = 0; i < M; ++i) {
			int s = sc.nextInt();
			int e = sc.nextInt();
			map[s][e] = true;
		}

		// solve
		int res = solve();
		
		// data output
		System.out.println(res);
	}

	private static int solve() {
		/// 행과 열을 검사하여 true인 부분을 검사해나간다.
		int res = 0;
		for (int i = 1; i <= N; ++i) {
			chk = new boolean[N + 1];
			chk[i] = true;
			findMin(i);
			findMax(i);
			// 전부 다 방문되었는지 확인
			boolean flag = true;
			for(int j = 1; j <= N; ++j)
				if(chk[j] == false) {
					flag = false;
					break;
				}
			if(flag)
				++res;
		}
		return res;
	}
	
	private static void findMin(int idx) {
		for (int i = 1; i <= N; ++i) {
			if (map[i][idx]) { // 자기 자신보다 작은애 탐색
				if(chk[i])
					continue;
				chk[i] = true;
				findMin(i);
			}
		}
	}
	private static void findMax(int idx) {
		for (int i = 1; i <= N; ++i) {
			if (map[idx][i]) { // 자기 자신보다 큰애 탐색
				if(chk[i])
					continue;
				chk[i] = true;
				findMax(i);
			}
		}
	}

}
