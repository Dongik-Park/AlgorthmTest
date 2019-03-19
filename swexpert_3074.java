package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class swexpert_3074 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int TC = Integer.parseInt(br.readLine());
		for (int testCase = 1; testCase <= TC; testCase++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int N = Integer.parseInt(st.nextToken()); // 1 <= N <= 10^5, �ɻ�� ����
			int M = Integer.parseInt(st.nextToken()); // 1 <= M <= 10^9, ����� �ο���
			int[] t = new int[N];
			for (int i = 0; i < N; i++) {
				t[i] = Integer.parseInt(br.readLine().trim()); // 1 <= tk <= 10^9
			}
			long start = 0;
			long end = 1000000000L * M;
			long min = Long.MAX_VALUE; // time �ּҰ�
			while(start <= end) {
				long mid = (start + end) / 2;
				long cnt = 0; // ������ mid �ð��ȿ� ����� �� �ִ� �ο���
				for (int i = 0; i < t.length; i++) {
					cnt += mid / t[i];
				}
				if (cnt >= M && min > mid) {
					min = mid;
				}
				if (cnt < M) {
					start = mid + 1;
				} else if (M <= cnt) {
					end = mid - 1;
				}
			} // end of while
			
			System.out.println("#"+testCase+" "+min);
		} // end of for testCase
	}
}
