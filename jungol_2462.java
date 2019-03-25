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
		/// ��� ���� �˻��Ͽ� true�� �κ��� �˻��س�����.
		int res = 0;
		for (int i = 1; i <= N; ++i) {
			chk = new boolean[N + 1];
			chk[i] = true;
			findMin(i);
			findMax(i);
			// ���� �� �湮�Ǿ����� Ȯ��
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
			if (map[i][idx]) { // �ڱ� �ڽź��� ������ Ž��
				if(chk[i])
					continue;
				chk[i] = true;
				findMin(i);
			}
		}
	}
	private static void findMax(int idx) {
		for (int i = 1; i <= N; ++i) {
			if (map[idx][i]) { // �ڱ� �ڽź��� ū�� Ž��
				if(chk[i])
					continue;
				chk[i] = true;
				findMax(i);
			}
		}
	}

}
