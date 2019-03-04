package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class baekjoon_16235 {
	static int N, M, K;
	static final int MAX_N = 10;
	static int map[][] = new int[MAX_N + 1][MAX_N + 1];
	static int A[][] = new int[MAX_N + 1][MAX_N + 1];
	static final int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
	static final int dy[] = { 0, 0, -1, 1, -1, -1, 1, 1 };

	static PriorityQueue<Tree> trees = new PriorityQueue<>(new Comparator<Tree>() {
		@Override
		public int compare(Tree o1, Tree o2) {
			return o1.age - o2.age;
		}
	}); // tree ť 

	static PriorityQueue<Tree> tempQue = new PriorityQueue<>(new Comparator<Tree>() {
		@Override
		public int compare(Tree o1, Tree o2) {
			return o1.age - o2.age;
		}
	}); // tree�� �����ϱ� ���� �ӽ�ť
	
	static class Tree {
		int r;
		int c;
		int age;

		public Tree(int r, int c, int age) {
			this.r = r;
			this.c = c;
			this.age = age;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		// data input
		String s[] = br.readLine().split(" ");
		N = Integer.parseInt(s[0]);
		M = Integer.parseInt(s[1]);
		K = Integer.parseInt(s[2]);
		for (int i = 1; i <= N; ++i) {
			String s1[] = br.readLine().split(" ");
			for (int j = 1; j <= N; ++j) {
				A[i][j] = Integer.parseInt(s1[j - 1]);
				map[i][j] = 5;
			}
		}
		for (int i = 0; i < M; ++i) {
			String s2[] = br.readLine().split(" ");
			trees.add(new Tree(Integer.parseInt(s2[0]), Integer.parseInt(s2[1]), Integer.parseInt(s2[2])));
		}
		
		bw.write(solve() + "");
		bw.flush();
		bw.close();
		br.close();
	}

	private static int solve() throws IOException {
		// k�⸸ŭ �ݺ�
		for (int i = 0; i < K; ++i)
			loop();
		// ��Ƴ��� �� ��ȯ
		return trees.size();
	}

	private static void loop() throws IOException {
		tempQue.clear();
		List<Tree> list = new ArrayList<>();
		// 1. ��
		while(!trees.isEmpty()) {
			Tree cur = trees.poll();
			if (map[cur.r][cur.c] >= cur.age) { // ����� ���� �� �ִ� ���
				map[cur.r][cur.c] -= cur.age;
				++cur.age;
				tempQue.add(cur); // �ӽ� ť�� ����
			} else { // ����� ���� �� ���� ��� ��� ����
				list.add(cur);
			}
		}
		// 2. ����
		for (int i = 0; i < list.size(); ++i) {
			Tree cur = list.get(i);
			map[cur.r][cur.c] += cur.age / 2;
		}
		trees.clear();
		// 3. ����
		while(!tempQue.isEmpty()){ // �ӽ� ť�� �����͸� �̿��Ͽ� tree ť�� �߰�
			Tree cur = tempQue.poll();
			trees.add(cur);
			if (cur.age % 5 == 0) {
				for (int i = 0; i < dx.length; ++i) {
					int nr = cur.r + dx[i];
					int nc = cur.c + dy[i];
					if (nr < 1 || nr > N || nc < 1 || nc > N)
						continue;
					trees.add(new Tree(nr, nc, 1));
				}
			}
		}
		// 4. �ܿ�
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				map[i][j] += A[i][j];
	}
}
