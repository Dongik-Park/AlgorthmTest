package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class baekjoon_2004 {
	/**
	 * num�� 2�� ������ ��ȯ���ִ� �޼���
	 * @param num 2�� ������ ��ȯ�� ����
	 * @return 2�� ����
	 */
	public static long countTwo(int num) {
	    long i;
	    long t = 0;
	 
	    for (i = 2; i <= num; i *= 2)
	        t += num / i;
	    
	    return t;
	}
	/**
	 * num�� 5�� ������ ��ȯ���ִ� �޼���
	 * @param num 5�� ������ ��ȯ�� ����
	 * @return 5�� ����
	 */
	public static long countFive(int num) {
	    long i;
	    long f = 0;
	 
	    for (i = 5; i <= num; i *= 5)
	        f += num / i;
	    
	    return f;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer token = new StringTokenizer(br.readLine());

		// n!�� 0�� ����
		int n = Integer.parseInt(token.nextToken());
		long nFive = countFive(n); // 1 ~ n���� 5�� ����
		long nTwo = countTwo(n); // 1 ~ n���� 5�� ����

		// k!�� 0�� ����
		int k = Integer.parseInt(token.nextToken());
		long kFive = countFive(k);
		long kTwo = countTwo(k); // 1 ~ n���� 5�� ����

		// (n - k)!�� 0�� ����
		long nMinusKFive = countFive(n - k);
		long nMinusKTwo = countTwo(n - k); // 1 ~ n���� 5�� ����

		bw.write(Math.min(nFive - (kFive + nMinusKFive), nTwo - (kTwo + nMinusKTwo)) + "");
		bw.flush();

		bw.close();
		br.close();
	}
}
