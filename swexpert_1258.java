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
	 * 1. 0�� �ƴ� ���ڸ� ������ �� ������ ������, �ϴܳ��� �˻��ϰ�
	 * 2. ������, �ϴܳ� ��ǥ���� ��� 0���� Ȯ���Ѵ�.
	 * 3. ���� ������� �ٷ� ����, ���� ���� ���� ����, ���� ���� ���� ����, ���� �ϴ����� �ٷ� �Ʒ����� �˻��Ͽ� 0���� Ȯ��
	 * last. �簢���� ��� ��� true�� �����.
	 */
	private static boolean isRectangle(int x, int y) {
		int ������ = -1;
		for (int i = y; i < N; ++i) {
			if(map[x][i] == 0)
				break;
			������ = i;
		}
		int �ϴܳ� = -1;
		for (int i = x; i < N; ++i) {
			if(map[i][y] == 0)
				break;
			�ϴܳ� = i;
		}
		for(int i = x; i <= �ϴܳ�; ++i)
			for(int j = y; j <= ������; ++j)
				if(map[i][j] == 0)
					return false;
		// ���
		if(x - 1 >= 0) {
			for(int i = y; i <= ������; ++i) 
				if(map[x - 1][i] != 0)
					return false;
		}
		// �ϴ�
		if(�ϴܳ� + 1 < N) {
			for(int i = y; i <= ������; ++i) 
				if(map[�ϴܳ� + 1][i] != 0)
					return false;
		}
		// ����
		if(y - 1 >= 0) {
			for(int i = x; i <= �ϴܳ�; ++i)
				if(map[i][y - 1] != 0)
					return false;
		}
		// ����
		if(������  + 1 < N) {
			for(int i = x; i <= �ϴܳ�; ++i)
				if(map[i][������ + 1] != 0)
					return false;
		}
		// �簢�� ǥ��
		for(int i = x; i <= �ϴܳ�; ++i)
			for(int j = y; j <= ������; ++j)
				map[i][j] = 0;
		// ����ť�� �߰�
		res.add(new Point(�ϴܳ� - x + 1, ������ - y + 1));
		return true;
	}
}
