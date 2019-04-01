package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class swexpert_3378 {

	private static String[] prr;
	private static String[] qrr;
	private static int[] result;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; ++tc) {
			int p, q;
			String ss[] = br.readLine().trim().split(" ");
			p = Integer.parseInt(ss[0]);
			q = Integer.parseInt(ss[1]);
			prr = new String[p]; // ������ �ڵ�
			qrr = new String[q]; // ���� �ڵ�
			result = new int[q]; // ��� ����� ������ �迭

			Arrays.fill(result, -2); // ������� �ʴ� ���ڷ� �ʱ�ȭ

			/*
			 * int R, C, S, a, b, c, d, e, f; R = C = S = a = b = c = d = e = f = 0;
			 */
			// ��Ÿ�ϸ��� �������� �� �Է�
			for (int i = 0; i < p; ++i) {
				prr[i] = br.readLine();
			}
			// ����� ��Ÿ�ϸ��� �� �Է�
			for (int i = 0; i < q; ++i) {
				qrr[i] = br.readLine();
			}

			for (int r = 1; r <= 20; ++r) {
				for (int c = 1; c <= 20; ++c) {
					for (int s = 1; s <= 20; ++s) {
						if (isMasterCodePossible(r, c, s)) { // ������ �ڵ��� ��� ��쿡 �� üũ
							isUserCodePossible(r, c, s); // ������ ��� �ڵ� �࿡�� �������� üũ �� �迭�� ����
						}
					}
				}
			}

			// data output
			StringBuilder builder = new StringBuilder();
			builder.append("#").append(tc).append(" ");
			for (int i = 0; i < result.length; ++i)
				builder.append(result[i]).append(" ");
			System.out.println(builder.toString());
		} // end of test case

		br.close();
	} // end of main

	private static void isUserCodePossible(int r, int c, int s) {
		int rr = 0;
		int cc = 0;
		int ss = 0;
		for(int i = 0; i < qrr.length; ++i) {
			int res = r * rr + c * cc + s * ss; // ����� ��
			if(result[i] == -2) // ó�� ���� �����ϴ� ���
				result[i] = res; 
			else if(result[i] >= 0 && result[i] != res) // ó�� �����ϴ� ��찡 �ƴ϶��
				result[i] = -1; // ���� �������� �� �� �ִ� ���
			
			String str = qrr[i];
			for(int j = 0; j < str.length(); ++j) {
				if      (str.charAt(j) == '(') ++rr;
				else if (str.charAt(j) == ')') --rr;
				else if (str.charAt(j) == '{') ++cc;
				else if (str.charAt(j) == '}') --cc;
				else if (str.charAt(j) == '[') ++ss;
				else if (str.charAt(j) == ']') --ss;
			}
			
		}
	}

	private static boolean isMasterCodePossible(int r, int c, int s) {
		int rr = 0; // ()�� ����
		int cc = 0; // {}
		int ss = 0; // []

		for (int i = 0; i < prr.length; ++i) {
			int dot = 0; // .�� ����
			String str = prr[i]; // ������ �ڵ��� ����
			int j;
			for (j = 0; j < str.length(); ++j) {
				if (str.charAt(j) == '.')
					++dot;
				else
					break; // ���ڰ� ������ ����
			}
			
			if(r * rr + c * cc + s * ss != dot) // ��� ���� �˻��ϴ� �� �����̶� Ʋ���� ���� ��ȯ
				return false;
			
			for (; j < str.length(); ++j) { // . ���� ���� ���ں��� �˻�
				if      (str.charAt(j) == '(') ++rr;
				else if (str.charAt(j) == ')') --rr;
				else if (str.charAt(j) == '{') ++cc;
				else if (str.charAt(j) == '}') --cc;
				else if (str.charAt(j) == '[') ++ss;
				else if (str.charAt(j) == ']') --ss;
			}
		}

		return true; // ��� �� �˻縦 ����� ���
	}

}
