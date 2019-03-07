package com.ssafy.algo;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.PriorityQueue;

public class swexpert_1258 {
	static int N;
	static int map[][] = new int[100][100];
	static PriorityQueue<Point> res;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; ++tc) {
			// data input
			N = Integer.parseInt(br.readLine());
			for (int i = 0; i < N; ++i) {
				String s[] = br.readLine().split(" ");
				for (int j = 0; j < N; ++j) {
					map[i][j] = Integer.parseInt(s[j]);
				}
			}
			res = new PriorityQueue<>(new Comparator<Point>() {
				@Override
				public int compare(Point o1, Point o2) {
					if(o1.x * o1.y - o2.x * o2.y != 0)
						return o1.x * o1.y - o2.x * o2.y;
					else
						return o1.x - o2.x;
				}
			});

			// solve
			bw.write("#" + tc + " " + solve() + " ");
			while (!res.isEmpty()) {
				Point p = res.poll();
				bw.write(p.x + " " + p.y + " ");
			}
			bw.write("\n");
		}
		// flush data
		bw.flush();
		bw.close();
		br.close();
	}

	private static int solve() {
		int cnt = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (map[i][j] != 0 && isRectangle(i, j)) {
					++cnt;
				}
		return cnt;
	}

	/*
	 * 
	 * 1. 0이 아닌 숫자를 만나면 그 숫자의 우측끝, 하단끝을 검색하고
	 * 2. 우측끝, 하단끝 좌표까지 모두 0인지 확인한다.
	 * 3. 가장 상단행은 바로 윗줄, 가장 좌측 열은 좌촉, 가장 우측 열은 우측, 가장 하단행은 바로 아랫줄을 검색하여 0인지 확인
	 * last. 사각형일 경우 모두 true로 만든다.
	 */
	private static boolean isRectangle(int x, int y) {
		int 우측끝 = -1;
		for (int i = y; i < N; ++i) {
			if(map[x][i] == 0)
				break;
			우측끝 = i;
		}
		int 하단끝 = -1;
		for (int i = x; i < N; ++i) {
			if(map[i][y] == 0)
				break;
			하단끝 = i;
		}
		for(int i = x; i <= 하단끝; ++i)
			for(int j = y; j <= 우측끝; ++j)
				if(map[i][j] == 0)
					return false;
		// 상단
		if(x - 1 >= 0) {
			for(int i = y; i <= 우측끝; ++i) 
				if(map[x - 1][i] != 0)
					return false;
		}
		// 하단
		if(하단끝 + 1 < N) {
			for(int i = y; i <= 우측끝; ++i) 
				if(map[하단끝 + 1][i] != 0)
					return false;
		}
		// 좌측
		if(y - 1 >= 0) {
			for(int i = x; i <= 하단끝; ++i)
				if(map[i][y - 1] != 0)
					return false;
		}
		// 우측
		if(우측끝  + 1 < N) {
			for(int i = x; i <= 하단끝; ++i)
				if(map[i][우측끝 + 1] != 0)
					return false;
		}
		// 사각형 표시
		for(int i = x; i <= 하단끝; ++i)
			for(int j = y; j <= 우측끝; ++j)
				map[i][j] = 0;
		// 정답큐에 추가
		res.add(new Point(하단끝 - x + 1, 우측끝 - y + 1));
		return true;
	}
}
