package com.ssafy.algo;

import java.util.Scanner;

public class jungol_1077 {
	static int N, W;
	static int weight[];
	static int val[];
	static int res;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// data input
		N = sc.nextInt();
		W = sc.nextInt();
		weight = new int[N];
		val = new int[N];
		for (int i = 0; i < N; ++i) {
			weight[i] = sc.nextInt();
			val[i] = sc.nextInt();
		}

		// solve
		res = knapSackDP(W, weight, val, N);

		// data output
		System.out.println(res);
	}

	// Returns the maximum value that can be put in a knapsack of capacity W
	static int knapSackDP(int W, int wt[], int val[], int n) {
		int[] dp = new int[W + 1];

		// i�� ��������
		for (int i = 0; i < N; i++) {
			// j�� ���� ����
			// �� ���Ժ��� ���� �賶�� ������ ���Ѱ��� �����Ѵ�.
			for (int j = wt[i]; j <= W; j++) {
				dp[j] = Math.max(dp[j], dp[j - wt[i]] + val[i]);
			}
		}

		return dp[W];
	}
	
}
