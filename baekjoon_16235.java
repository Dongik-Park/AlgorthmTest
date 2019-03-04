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
	}); // tree 큐 

	static PriorityQueue<Tree> tempQue = new PriorityQueue<>(new Comparator<Tree>() {
		@Override
		public int compare(Tree o1, Tree o2) {
			return o1.age - o2.age;
		}
	}); // tree를 갱신하기 위한 임시큐
	
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
		// k년만큼 반복
		for (int i = 0; i < K; ++i)
			loop();
		// 살아남은 수 반환
		return trees.size();
	}

	private static void loop() throws IOException {
		tempQue.clear();
		List<Tree> list = new ArrayList<>();
		// 1. 봄
		while(!trees.isEmpty()) {
			Tree cur = trees.poll();
			if (map[cur.r][cur.c] >= cur.age) { // 양분을 먹을 수 있는 경우
				map[cur.r][cur.c] -= cur.age;
				++cur.age;
				tempQue.add(cur); // 임시 큐에 삽입
			} else { // 양분을 먹을 수 없는 경우 즉시 죽음
				list.add(cur);
			}
		}
		// 2. 여름
		for (int i = 0; i < list.size(); ++i) {
			Tree cur = list.get(i);
			map[cur.r][cur.c] += cur.age / 2;
		}
		trees.clear();
		// 3. 가을
		while(!tempQue.isEmpty()){ // 임시 큐의 데이터를 이용하여 tree 큐에 추가
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
		// 4. 겨울
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				map[i][j] += A[i][j];
	}
}
