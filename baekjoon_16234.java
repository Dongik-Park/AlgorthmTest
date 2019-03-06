package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class baekjoon_16234 {
	static int N, L, R;
	static final int MAX_N = 50;
	static int map[][] = new int[MAX_N][MAX_N];
	static int tmp_map[][] = new int[MAX_N][MAX_N];
	static boolean visited[][] = new boolean[MAX_N][MAX_N];
	static Country que[] = new Country[MAX_N * MAX_N]; 
	static int front, rear, sum;
	static int dx[] = { -1, 1, 0, 0 };
	static int dy[] = { 0, 0, -1, 1 };

	static class Country {
		int r;
		int c;
		int cnt;

		public Country(int r, int c, int cnt) {
			this.r = r;
			this.c = c;
			this.cnt = cnt;
		}

		@Override
		public String toString() {
			return "{r=" + r + ", c=" + c + ", cnt=" + cnt + "}";
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		// data input
		String s[] = br.readLine().split(" ");
		N = Integer.parseInt(s[0]);
		L = Integer.parseInt(s[1]);
		R = Integer.parseInt(s[2]);
		for (int i = 0; i < N; ++i) {
			String s1[] = br.readLine().split(" ");
			for (int j = 0; j < N; ++j) {
				map[i][j] = Integer.parseInt(s1[j]);
			}
		}

		boolean is_update = true;
		int res = 0;
		// queue ����
		while (is_update) {
			is_update = false;

			// ���� map ���� �� �湮 �� �ʱ�ȭ
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j) {
					tmp_map[i][j] = map[i][j];
					visited[i][j] = false;
				}

			// �Ϸ� ���� ����
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j) {
					if (!visited[i][j]) {
						sum = 0;
						front = rear = 0;
						dfs(i, j, que); // Ž�� ����
						if (rear - front <= 1) {// ������ �� �� �ִ� ������ 1�������� ���
							front = rear = 0;
							visited[i][j] = false;
							continue;
						}
						// ������ ������ ���
						int avg = sum / (rear - front); // ������ ��հ�
						while (front != rear) {
							Country cur = que[front++];
							tmp_map[cur.r][cur.c] = avg;
						}
						is_update = true;
					}
				}
			// �Ϸ� ���� ��� map�� �ݿ�
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j) {
					map[i][j] = tmp_map[i][j];
				}
			// �α� �̵��� �̷���� ���
			if (is_update)
				++res; // ���� Ƚ�� count
		}

		bw.write(res + "");
		bw.flush();
		bw.close();
		br.close();
	}

	static void dfs(int r, int c, Country que[]) {
		// ���� ���� �߰�
		Country newc = new Country(r, c, map[r][c]);
		que[rear++] = newc;
		visited[r][c] = true;
		sum += newc.cnt;// ������Ҹ� �����Ͽ� ���� ���Ѵ�.
		// 4�� �˻��Ͽ� ��� ����
		for (int dir = 0; dir < 4; ++dir) {
			int nr = r + dx[dir];
			int nc = c + dy[dir];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc])
				continue;
			if (Math.abs(map[r][c] - map[nr][nc]) >= L && Math.abs(map[r][c] - map[nr][nc]) <= R) {
				dfs(nr, nc, que);
			}
		}
	}
}
