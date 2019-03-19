package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
/**
 * �ȳ���		   : dfs
 * 200ms 16*16 : dfs ����ġ��
 * �޸������̼�      : ���
 */
public class swexpert_1865 {
	public static int N;
	public static int p[][];
	public static double memo[] = new double[1 << 16];

	public static void main(String[] ar) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		long time = System.currentTimeMillis();
		
		for (int tc = 1; tc <= T; tc++) {
			// data input
			N = Integer.parseInt(br.readLine());
			p = new int[N][N];
			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					p[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			// solve
			Arrays.fill(memo, -1); // ��ü�� ���� �����ϴ� �ͺ��� 40ms ����
			double res = f(0, 0);
			
			// data output
			System.out.printf("#%d %.6f\n", tc, res / Math.pow(100, N - 1));
		} // end of for testCase
		
		System.out.println(System.currentTimeMillis() - time + " ms");
	} // end of main

	/**
	 * step : N�� �������� �ϳ��� �����ذ��� �ܰ� flag : �̹� ������ �������� ��Ʈ�� ǥ���� �� �̹� ������ �������߿��� ������
	 * �ٲپ� �ִ�� ����� �ִ� ���� memo �迭�� ������ 12345 �� 21345 �� ������ ������ �������� 2��° step ����
	 * �������� ��� �ִ밪�� �ʿ��ϹǷ� 12 �� 21 �� ���� �ɼ� �ִ� ū���� �����Ѵ�. 1�� ����, 2�� ������ �����ϴ� ����� �ִ밪��
	 * 1,2 ���� ��Ʈ����ŷ �� flag�� index�� ����Ͽ� memo[flag] �� ����
	 */
	public static double f(int step, int flag) {
		if (step == N) {
			return 1;
		}
		if (memo[flag] >= 0) {
			return memo[flag];
		}
		double max = 0;
		for (int i = 0; i < N; i++) {
			int bitMask = 1 << i;
			if ((flag & bitMask) == 0) { // ������� ���� ���ڶ��
				double next = f(step + 1, flag | bitMask) * p[step][i];
				if (max < next) {
					max = next;
				}
			}
		}
		memo[flag] = max;
		return max;
	}
}
/*import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
*//*
public class Solution_1865_��ö�����Ϻй�1 {
	private static double[][] p;
	private static double max;
	private static int N;
	private static int[] select;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int TC = Integer.parseInt(br.readLine());
		long time = System.currentTimeMillis();
		for (int testCase = 1; testCase <= TC; testCase++) {
			N = Integer.parseInt(br.readLine()); // 1 <= N <= 16

			p = new double[N][N];
			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < N; j++) {
					p[i][j] = Integer.parseInt(st.nextToken()) / 100D; // 1 <= Pij <= 100
				}
			}
			select = new int[N];
			for (int i = 0; i < N; i++) {
				select[i] = i;
			}
			max = 0;
			f(0, 100d);
			
			System.out.printf("#%d %.6f\n", testCase, max); // �ݿø� �Ҽ��� �Ʒ� 6°�ڸ����� ���
		} // end of for testCase
		System.out.println(System.currentTimeMillis() - time + " ms");
	} // end of main
	public static void f(int step, double pp) {
		if (step == N) {
			if (max < pp) {
				max = pp;
			}
		} else {
			for (int i = step; i < N; i++) {
				swap(step, i);
				if (max < pp*p[step][select[step]]) {
					f(step+1, pp*p[step][select[step]]);
				}
				swap(step, i);
			}
		}
	}
	public static void swap(int i, int j) {
		int temp = select[i];
		select[i] = select[j];
		select[j] = temp;
	}
} // end of class
*/