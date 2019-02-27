package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class swexpert_6485 {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; ++tc) {
			// data input
			int cnt[] = new int[5001];
			int N = Integer.parseInt(br.readLine());
			int A[] = new int[N];
			int B[] = new int[N];
			for(int i = 0; i < N; ++i) {
				String s[] = br.readLine().split(" ");
				A[i] = Integer.parseInt(s[0]);
				B[i] = Integer.parseInt(s[1]);
				for(int j = A[i]; j <= B[i]; ++j) // check route
					++cnt[j];
			}
			int P = Integer.parseInt(br.readLine());
			int C[] = new int[P];
			for(int i = 0; i < P; ++i) {
				C[i] = Integer.parseInt(br.readLine());
			}
			
			bw.write("#" + tc + " ");
			for(int i = 0; i < P; ++i) {
				bw.write(cnt[C[i]] + " ");
			}
			bw.write("\n");
		}
		bw.flush();
		
		bw.close();
		br.close();
	}
}
