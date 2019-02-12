package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swexpert_1266 {
	static double skillOfMasterA;
	static double skillOfMasterB;
	static int[] primes = { 2, 3, 5, 7, 11, 13, 17 };
	static long[] factorial = new long[19];

	public static void factorial() { // 팩토리얼 공식
		factorial[0] = 1;
		for (int i = 1; i < factorial.length; i++) {
			factorial[i] = factorial[i - 1] * i;
		}
	}

	public static long nCr(int n, int r) { // 조합 공식
		long res = 0L;
		res = factorial[n] / (factorial[n - r] * factorial[r]);
		return res;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		factorial();
		for (int tc = 1; tc <= T; ++tc) {
			// data input & init
			StringTokenizer token = new StringTokenizer(br.readLine());
			skillOfMasterA = Double.parseDouble(token.nextToken());
			skillOfMasterB = Double.parseDouble(token.nextToken());

			double sumA = 0;
			double sumB = 0;
			for (int j = 0; j < primes.length; j++) { // 18C현재소수 * 소수가 될 확률 * 소수가 아닐 확률
				sumA += nCr(18, primes[j]) * (Math.pow(skillOfMasterA / 100, primes[j]) * Math.pow((100 - skillOfMasterA) / 100, 18 - primes[j]));
				sumB += nCr(18, primes[j]) * (Math.pow(skillOfMasterB / 100, primes[j]) * Math.pow((100 - skillOfMasterB) / 100, 18 - primes[j]));
			}
			
			// data output
			System.out.printf("#%d %.6f\n", tc, sumA + sumB - (sumA * sumB));
		}
	}

}
