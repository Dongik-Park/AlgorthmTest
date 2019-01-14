package com.ssafy.algo;

import java.util.Scanner;
/**
* 현재 : 가장 상단에서 1인 경우 아래로 탐색한다.
* 개선 : 가장 하단에서 2인 경우부터 위로 탐색한다.
*/
public class Solution1210 {
	
	private static final int size = 100;
	private static int[][] ladder = new int[size][size];
	
	/**
	 * 종료 여부를 확인하는 DFS 메소드
	 * @param row 검사를 시작할 열
	 * @param col 검사를 시작할 행
	 * @return 정상 종료 여부
	 */
	private static boolean isFinished(int row, int col) {
		if(col > 0 && col < size - 1) { // 사이 열
			for(int i = row; i < size; ++i) {
				if(ladder[i][col] == 2) return true;
				else if(ladder[i][col - 1] == 1) { // 좌측
					for(int j = col - 1; j >= 0 ; --j) {
						if(i + 1 < size && ladder[i + 1][j] == 1)
							return isFinished(i + 1, j);
					}
				}
				else if(ladder[i][col + 1] == 1) { // 우측 
					for(int j = col + 1; j < size; ++j){
						if(i + 1 < size && ladder[i + 1][j] == 1)
							return isFinished(i + 1, j);
					}
				}
			}
		}
		else if(col == 0) { // 가장 좌측 열
			for(int i = row; i < size; ++i) {
				if(ladder[i][col] == 2) return true;
				else if(ladder[i][col + 1] == 1) { // 우측만
					for(int j = col + 1; j < size; ++j){
						if(i + 1 < size && ladder[i + 1][j] == 1)
							return isFinished(i + 1, j);
					}
				}
			}
		}
		else if(col == size - 1) { // 가장 우측 열
			for(int i = row; i < size; ++i) {
				if(ladder[i][col] == 2) return true;
				else if(ladder[i][col - 1] == 1) { // 좌측만
					for(int j = col - 1; j >= 0 ; --j) {
						if(i + 1 < size && ladder[i + 1][j] == 1)
							return isFinished(i + 1, j);
					}
				}
			}
		}
		return false;
	}
	
	private static int solve() {
		for(int i = 0; i < size; ++i) 
			if(ladder[0][i] == 1 && isFinished(1, i)) 
					return i;
		return -1;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		for(int tc = 1; tc <= 10; ++tc) {
			sc.nextInt();
			
			for(int i = 0; i < size; ++i)
				for(int j = 0; j < size; ++j)
					ladder[i][j] = sc.nextInt();
			
			System.out.println("#" + tc + " " + solve());
		}
	}
}
