package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 가로 세로의 합이 홀수개 인것을 확인하면 된다. 
 * 
 * @author student
 *
 */
public class swexpert_6731 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int tc = Integer.parseInt(br.readLine().trim());

		for (int t = 1; t <= tc; t++) {
			int answer = 0;
			// data input
			int n = Integer.parseInt(br.readLine().trim());
			int[][] map = new int[n][n];
			int[] bRow = new int[n];
			int[] bCol = new int[n];
			
			// check row data
			for (int i = 0; i < n; i++) {
				String line = br.readLine();
				int rowSum = 0;
				for (int j = 0; j < n; j++) {
					map[i][j] = line.charAt(j) == 'W' ? 0 : 1;
					rowSum += map[i][j];
				}
				bRow[i] = rowSum;
			}
			// check col data
			for (int j = 0; j < n; j++) {
				int colSum = 0;
				for (int i = 0; i < n; i++) {
					colSum += map[i][j];
				}
				bCol[j] = colSum;
			}
			
			// 각 점에서 가로와 세로 b의 합을 합해서(자기는 중복이므로 -1) 홀수 여부 확인
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (((bRow[i] + bCol[j] - map[i][j]) & 1) == 1) {
						answer++;
					}
				}
			}
			
			// data output
			sb.append("#").append(t).append(" ").append(answer).append("\n");
		}
		System.out.println(sb);
	}
}
