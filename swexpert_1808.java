package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class swexpert_1808 {

	private static boolean chk[]; // ���� ���� ���� ����

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; ++tc) {
			// data input
			String s[] = br.readLine().trim().split(" ");
			chk = new boolean[10];
			for (int i = 0; i < 10; ++i) {
				if (Integer.parseInt(s[i]) == 1) {
					chk[i] = true;
				}
			}
			// solve
			int X = Integer.parseInt(br.readLine().trim());
			int res2 = solve2(X);
			
			//data output
			System.out.println("#" + tc + " " + (res2 == -1 ? -1 : res2 + 1));
		}

	}

	private static int solve2(int X) {
		//  System.out.println(X + "������");
		int res = Integer.MAX_VALUE;
		for (int i = 2; i * i <= X; ++i) {
			if (X % i == 0) { // X�� ���� ���ڷ� ������ ������ ���
				int cur = isPossible(i); // 1�� �ڸ����� Ŭ�� ������ ���
				if (cur != -1) { 
					int next = solve2(X / i); // ���ڸ� ������ �ٽ� �����Ѵ�.
					if (next != -1) { // ������ �����Ͽ��� �� 1�� �ڸ����� Ŭ���� �����Ͽ� Ŭ���� ���� Ƚ������ -1�� �ƴ� ���
						res = (res > (next + cur + 1)) ? (cur + next + 1) : res;
					}
				}
			}
		}

		int a = isPossible(X); // 1�� �ڸ����� Ŭ�� �������� Ȯ��

		if (res == Integer.MAX_VALUE) { // ������ �����͸� ��ã�� ��� 1�� �ڸ���Ȯ��
			return (a != -1) ? a : -1;
		} else // ���� �ݺ������� �����͸� ã�� ��� �ѹ��� Ŭ���Ǵ� �� ���� Ȯ��
			return (a != -1 && a < res) ? a : res;
	}

	private static int isPossible(int num) {
		if (num < 10)
			return chk[num] ? 1 : -1;
		else {
			if (chk[num % 10]) { // 1�� �ڸ����� �˻��Ͽ� �Է°����� ���
				int next = isPossible(num / 10); // 10�� ���� ���� �����Ѵ�.
				return next == -1 ? -1 : next + 1; // ���������� �Է� ������ ��� -1�� �ƴϰ�, ���⿡ ���� Ƚ���� �߰��Ͽ� ��ȯ
			} else
				return -1;
		}
	}
}
