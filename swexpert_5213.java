package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class swexpert_5213 {
	static long f[] = new long[1000001]; // Ȧ�� ����� ���� ������ �迭
	static long sum[] = new long[f.length]; // ������� Ȧ�� ������� ���� ������ �迭

	public static void makeArray() {
		for(int i = 1; i < f.length; ++i) {
			// 1. ���� ������ Ȧ�� ��� ���� ���Ѵ�.
			// 1-1. 1 ~ ������ڱ��� ���� ��� �߿���
			for(int j = 1; j * j <= i; ++j) { 
				if(i % j == 0) { // ��� �߿��� 
					if((j & 1) == 1) // Ȧ���� ��� ( 1�� ������ ���� )
						f[i] += j;
					if(j != (i / j) && ((i / j) & 1) == 1) { // i�� j�� �������� �ƴϰ� i�� j�� ���������� �������� 1�� ���
						f[i] += (i / j); // i / j�� ���Ѵ�.
					}
				}
			}
			sum[i] += (sum[i - 1] + f[i]); // ��������� ����� �����Ѵ�.
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine());
		makeArray(); // ����迭 ����

		for (int tc = 1; tc <= T; ++tc) { // �����͸� ������ ť ����
			String s[] = br.readLine().split(" ");
			int L = Integer.parseInt(s[0]);
			int R = Integer.parseInt(s[1]);
			
			// data output
			long result = sum[R] - sum[L - 1];
			bw.write("#" + tc + " " + result + "\n");
		}

		bw.flush();

		br.close();
		bw.close();
	}
}
