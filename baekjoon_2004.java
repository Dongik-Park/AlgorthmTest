package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class baekjoon_2004 {
	/**
	 * num의 2의 개수를 반환해주는 메서드
	 * @param num 2의 개수를 반환할 숫자
	 * @return 2의 개수
	 */
	public static long countTwo(int num) {
	    long i;
	    long t = 0;
	 
	    for (i = 2; i <= num; i *= 2)
	        t += num / i;
	    
	    return t;
	}
	/**
	 * num의 5의 개수를 반환해주는 메서드
	 * @param num 5의 개수를 반환할 숫자
	 * @return 5의 개수
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

		// n!의 0의 개수
		int n = Integer.parseInt(token.nextToken());
		long nFive = countFive(n); // 1 ~ n까지 5의 개수
		long nTwo = countTwo(n); // 1 ~ n까지 5의 개수

		// k!의 0의 개수
		int k = Integer.parseInt(token.nextToken());
		long kFive = countFive(k);
		long kTwo = countTwo(k); // 1 ~ n까지 5의 개수

		// (n - k)!의 0의 개수
		long nMinusKFive = countFive(n - k);
		long nMinusKTwo = countTwo(n - k); // 1 ~ n까지 5의 개수

		bw.write(Math.min(nFive - (kFive + nMinusKFive), nTwo - (kTwo + nMinusKTwo)) + "");
		bw.flush();

		bw.close();
		br.close();
	}
}
