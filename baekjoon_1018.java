package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class baekjoon_1018 {
	private static int N;
	private static int M;
	private static int res;
	private static char[][] map;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// data input
		StringTokenizer token = new StringTokenizer(br.readLine());
		N = Integer.parseInt(token.nextToken());
		M = Integer.parseInt(token.nextToken());
		map = new char[N][M];
		
		for(int i = 0; i < N; ++i) {
			String s = br.readLine();
			for(int j = 0; j < M; ++j) {
				map[i][j] = s.charAt(j);
			}
		}
		
		// solve
		res = 64;
		for(int i = 0; i <= N - 8; ++i)
			for(int j = 0; j <= M - 8; ++j)
				solve(i, j);
		
		// data output
		System.out.println(res);
	}

	private static void solve(int r, int c) {
		int wcnt = 0; // 1. 좌측상단 W인 경우
		int bcnt = 0; // 2. 좌측상단 B인 경우
		for(int i = r; i < r + 8; ++i) {
			if((i & 1) == 0) { // 짝수행에 대해 
				for(int j = c; j < c + 8; ++j) {
					if((j & 1) == 0) {
						if(map[i][j] == 'W')
							++bcnt;
						else
							++wcnt;
					}
					if((j & 1) == 1) {
						if(map[i][j] == 'B')
							++bcnt;
						else
							++wcnt;
					}
				}
			}
			else { // 홀수행에 대해
				for(int j = c; j < c + 8; ++j) {
					if((j & 1) == 0) {
						if(map[i][j] == 'B')
							++bcnt;
						else
							++wcnt;
					}
					if((j & 1) == 1)
						if(map[i][j] == 'W')
							++bcnt;
						else
							++wcnt;
				}
			}
		}
		res = Math.min(res, Math.min(bcnt, wcnt));
	}
}
