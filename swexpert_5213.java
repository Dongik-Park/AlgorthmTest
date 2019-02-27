package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class swexpert_5213 {
	static long f[] = new long[1000001]; // 홀수 약수의 합을 저장할 배열
	static long sum[] = new long[f.length]; // 현재까지 홀수 약수들의 합을 저장할 배열

	public static void makeArray() {
		for(int i = 1; i < f.length; ++i) {
			// 1. 현재 숫자의 홀수 약수 합을 구한다.
			// 1-1. 1 ~ 현재숫자까지 중의 약수 중에서
			for(int j = 1; j * j <= i; ++j) { 
				if(i % j == 0) { // 약수 중에서 
					if((j & 1) == 1) // 홀수일 경우 ( 1은 무조건 포함 )
						f[i] += j;
					if(j != (i / j) && ((i / j) & 1) == 1) { // i가 j의 제곱수가 아니고 i와 j를 나누었을때 나머지가 1일 경우
						f[i] += (i / j); // i / j를 더한다.
					}
				}
			}
			sum[i] += (sum[i - 1] + f[i]); // 현재까지의 결과를 누적한다.
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine());
		makeArray(); // 결과배열 생성

		for (int tc = 1; tc <= T; ++tc) { // 데이터를 누적할 큐 생성
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
