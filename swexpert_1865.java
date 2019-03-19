package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
/**
 * 안끝남		   : dfs
 * 200ms 16*16 : dfs 가지치기
 * 메모이제이션      : 즉시
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
			Arrays.fill(memo, -1); // 객체를 새로 생성하는 것보다 40ms 빠름
			double res = f(0, 0);
			
			// data output
			System.out.printf("#%d %.6f\n", tc, res / Math.pow(100, N - 1));
		} // end of for testCase
		
		System.out.println(System.currentTimeMillis() - time + " ms");
	} // end of main

	/**
	 * step : N개 순열에서 하나씩 선택해가는 단계 flag : 이미 선택한 정점들을 비트로 표시한 값 이미 선택한 정점들중에서 순서를
	 * 바꾸어 최대로 만들수 있는 값을 memo 배열에 저장함 12345 와 21345 의 순열을 만들어가는 과정에서 2번째 step 까지
	 * 선택했을 경우 최대값이 필요하므로 12 와 21 중 답이 될수 있는 큰값만 저장한다. 1번 정점, 2번 정점을 선택하는 경우의 최대값을
	 * 1,2 번을 비트마스킹 한 flag를 index로 사용하여 memo[flag] 에 저장
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
			if ((flag & bitMask) == 0) { // 사용하지 않은 숫자라면
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
public class Solution_1865_동철이의일분배1 {
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
			
			System.out.printf("#%d %.6f\n", testCase, max); // 반올림 소수점 아래 6째자리까지 출력
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