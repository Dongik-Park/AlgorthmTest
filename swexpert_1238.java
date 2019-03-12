package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class swexpert_1238 {
	static boolean map[][];
	static boolean visited[];
	static int maxFrom;
	static int maxTo;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int tc = 1; tc <= 1; ++tc) {
			// data input
			map = new boolean[101][101];
			visited = new boolean[101];
			maxFrom = 0;
			maxTo = 0;
			String s[] = br.readLine().split(" ");
			int len = Integer.parseInt(s[0]);
			int start = Integer.parseInt(s[1]);
			s = br.readLine().split(" ");
			for(int i = 0; i < len; i += 2) {
				int from = Integer.parseInt(s[i]);
				int to = Integer.parseInt(s[i + 1]);
				map[from][to] = true;
				maxFrom = Math.max(maxFrom, from);
				maxTo = Math.max(maxTo, to);
			}
			
			// solve
			int res = BFS(start);
			//data output
			System.out.println("#" + tc + " " + res);
		}
			
	}
	private static int BFS(int v) {
		// 정점 방문
		Queue<Integer> que = new LinkedList<>();
		que.add(v);
		
		int res = 0;
		while(!que.isEmpty()) {
			int temp = 0;
			int size = que.size();
			for(int i = 0; i < size; ++i) {
				int cur = que.remove();
				visited[cur] = true;
				// 현재 정점과 연결된 지점에 대해 큐에 추가한다.
				for(int j = 0; j <= maxTo; ++j)
					if(map[cur][j] && !visited[j]) {
						visited[j] = true;
						que.add(j);
					}
				temp = Math.max(temp, cur);
			}
			res = temp;
		}
		
		return res;
	}

}
