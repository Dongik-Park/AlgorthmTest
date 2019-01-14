package com.ssafy.algo;

import java.util.Scanner;

public class Solution1210 {
	
	private static final int size = 100;
	private static int[][] ladder = new int[size][size];
	
	/**
	 * ���� ���θ� Ȯ���ϴ� DFS �޼ҵ�
	 * @param row �˻縦 ������ ��
	 * @param col �˻縦 ������ ��
	 * @return ���� ���� ����
	 */
	private static boolean isFinished(int row, int col) {
		if(col > 0 && col < size - 1) { // ���� ��
			for(int i = row; i < size; ++i) {
				if(ladder[i][col] == 2) return true;
				else if(ladder[i][col - 1] == 1) { // ����
					for(int j = col - 1; j >= 0 ; --j) {
						if(i + 1 < size && ladder[i + 1][j] == 1)
							return isFinished(i + 1, j);
					}
				}
				else if(ladder[i][col + 1] == 1) { // ���� 
					for(int j = col + 1; j < size; ++j){
						if(i + 1 < size && ladder[i + 1][j] == 1)
							return isFinished(i + 1, j);
					}
				}
			}
		}
		else if(col == 0) { // ���� ���� ��
			for(int i = row; i < size; ++i) {
				if(ladder[i][col] == 2) return true;
				else if(ladder[i][col + 1] == 1) { // ������
					for(int j = col + 1; j < size; ++j){
						if(i + 1 < size && ladder[i + 1][j] == 1)
							return isFinished(i + 1, j);
					}
				}
			}
		}
		else if(col == size - 1) { // ���� ���� ��
			for(int i = row; i < size; ++i) {
				if(ladder[i][col] == 2) return true;
				else if(ladder[i][col - 1] == 1) { // ������
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
