package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class swexpert_1263 {
	static int N;
	static int map[][];
	static final int MAX_INT = 987654321;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; ++tc) {
			// data input
			String[] s = br.readLine().split(" ");
			int idx = 0;
			N = Integer.parseInt(s[0]);
			map = new int[N][N];
			for(int i = 0; i < N; ++i) {
				for(int j = 0; j< N; ++j) {
					map[i][j] = Integer.parseInt(s[++idx]);
					if(map[i][j] == 0)
						map[i][j] = MAX_INT;
				}
			}
			
			floyd(); // 플로이드 알고리즘
			
			int result = MAX_INT;
			for(int i = 0; i < N; ++i) {
				int curSum = 0;
				for(int j = 0; j < N; ++j)
					if(map[i][j] < MAX_INT)
						curSum += map[i][j];
				result = Math.min(curSum, result);
			}
			
			// solve
			bw.write("#" + tc + " " + result + "\n");
		}
		// flush data
		bw.flush();
		bw.close();
		br.close();
	} 
	private static void floyd() { // 풀로이드 알고리즘
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (i == j) {
                        continue;
                    }
                    if (map[i][j] > map[i][k] + map[k][j]) {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }
    }
}