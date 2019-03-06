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
		// queue 생성
		while (is_update) {
			is_update = false;

			// 현재 map 복사 및 방문 맵 초기화
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j) {
					tmp_map[i][j] = map[i][j];
					visited[i][j] = false;
				}

			// 하루 연합 진행
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j) {
					if (!visited[i][j]) {
						sum = 0;
						front = rear = 0;
						dfs(i, j, que); // 탐색 시작
						if (rear - front <= 1) {// 국경을 열 수 있는 국가가 1개이하인 경우
							front = rear = 0;
							visited[i][j] = false;
							continue;
						}
						// 연합이 가능한 경우
						int avg = sum / (rear - front); // 국가의 평균값
						while (front != rear) {
							Country cur = que[front++];
							tmp_map[cur.r][cur.c] = avg;
						}
						is_update = true;
					}
				}
			// 하루 연합 결과 map에 반영
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j) {
					map[i][j] = tmp_map[i][j];
				}
			// 인구 이동이 이루어진 경우
			if (is_update)
				++res; // 연합 횟수 count
		}

		bw.write(res + "");
		bw.flush();
		bw.close();
		br.close();
	}

	static void dfs(int r, int c, Country que[]) {
		// 현재 원소 추가
		Country newc = new Country(r, c, map[r][c]);
		que[rear++] = newc;
		visited[r][c] = true;
		sum += newc.cnt;// 현재원소를 포함하여 합을 구한다.
		// 4방 검색하여 계속 진행
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
