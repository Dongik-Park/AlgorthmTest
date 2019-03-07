package com.ssafy.algo;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class jungol_2606 {
	static int N, M, H;
	static final int dx[] = { 0, 0, 0, 0, 1, -1 };
	static final int dy[] = { 0, 0, -1, 1, 0, 0 };
	static final int[] dz = { -1, 1, 0, 0, 0, 0 }; // 위아래상하좌우
	static int[][][] tomato;

	static class Tomato {
		int x;
		int y;
		int z;

		public Tomato(int z, int x, int y) {
			this.z = z;
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		// data input
		M = sc.nextInt();
		N = sc.nextInt();
		H = sc.nextInt();
		tomato = new int[H][N][M];
		Queue<Tomato> 토마토큐 = new LinkedList<>();
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					tomato[i][j][k] = sc.nextInt();
					if (tomato[i][j][k] == 1) {
						토마토큐.add(new Tomato(i, j, k));
					}
				}
			}
		}
		// solve
		while (!토마토큐.isEmpty()) {
			Tomato cur = 토마토큐.poll();
			int tX = cur.x;
			int tY = cur.y;
			int tZ = cur.z;
			for (int i = 0; i < dx.length; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				int nz = cur.z + dz[i];
				
				if (nz < 0 || nx < 0 || ny < 0 || nz >= H || nx >= N || ny >= M || tomato[nz][nx][ny] != 0) {
					continue;
				}
				tomato[nz][nx][ny] = tomato[tZ][tX][tY] + 1;
				토마토큐.add(new Tomato(nz, nx, ny));
			}
		}
		// find max value
		int res = Integer.MIN_VALUE;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (tomato[i][j][k] == 0) {
						System.out.println("-1");
						return;
					}
					res = Math.max(res, tomato[i][j][k]);
				}
			}
		}
		// data output
		System.out.println((res - 1) + "");
	}

}