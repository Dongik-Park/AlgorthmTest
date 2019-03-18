package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class swexpert_1824 {
	static class KeyList {
		ArrayList<String> key;
	}
	static char map[][] = new char[20][20];
	static KeyList[][] keyList = new KeyList[20][20];
	private static int R;
	private static int C;
	private static String res;
	private static int memory;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; ++tc) {
			// data input
			String s[] = br.readLine().trim().split(" ");
			R = Integer.parseInt(s[0]);
			C = Integer.parseInt(s[1]);
			boolean flag = false;
			for (int i = 0; i < R; ++i) {
				String str = br.readLine().trim();
				for (int j = 0; j < str.length(); ++j) {
					map[i][j] = str.charAt(j);
					keyList[i][j] = new KeyList();
					keyList[i][j].key = new ArrayList<>();
					if (map[i][j] == '@')
						flag = true;
				}
			}

			// solve
			res = "NO";
			memory = 0;
			if (flag)
				dfs(0, 0, 1);

			// data output
			System.out.println("#" + tc + " " + res);
		}
	}

	private static void dfs(int r, int c, int dir) {
		if (res.equals("YES"))
			return;
		// 이전에 똑같은 방향과 키로 들어왔을 경우 NO
		for (int i = 0; i < keyList[r][c].key.size(); ++i) {
			if (keyList[r][c].key.get(i).equals(memory + "" + dir + "")) {
				res = "NO";
				return;
			}
		}
		// 현재 이동 키 추가
		keyList[r][c].key.add(memory + "" + dir + "");
		int tempMem = memory;

		if (map[r][c] == '@') { // 종료 조건
			res = "YES";
			return;
		}
		else if (map[r][c] >= '0' && map[r][c] <= '9') { // 숫자일 경우
			memory = map[r][c] - '0';
			if (dir == 0) {
				if (c - 1 >= 0)
					dfs(r, c - 1, 0);
				else
					dfs(r, C - 1, 0);
			} else if (dir == 1) {
				if (c + 1 < C)
					dfs(r, c + 1, 1);
				else
					dfs(r, 0, 1);
			} else if (dir == 2) {
				if (r - 1 >= 0)
					dfs(r - 1, c, 2);
				else
					dfs(R - 1, c, 2);
			} else if (dir == 3) {
				if (r + 1 < R)
					dfs(r + 1, c, 3);
				else
					dfs(0, c, 3);
			}
		} else if (map[r][c] == '<') { // 좌측일 경우
			if (c - 1 >= 0)
				dfs(r, c - 1, 0);
			else
				dfs(r, C - 1, 0);
		} else if (map[r][c] == '>') { // 우측일 경우
			if (c + 1 < C)
				dfs(r, c + 1, 1);
			else
				dfs(r, 0, 1);
		} else if (map[r][c] == '^') { // 상측일 경우
			if (r - 1 >= 0)
				dfs(r - 1, c, 2);
			else
				dfs(R - 1, c, 2);
		} else if (map[r][c] == 'v') { // 하측일 경우
			if (r + 1 < R)
				dfs(r + 1, c, 3);
			else
				dfs(0, c, 3);
		} else if (map[r][c] == '_') { // 메모리에 0이 저장되어 있으면 이동 방향을 오른쪽으로 바꾸고, 아니면 왼쪽으로 바꾼다.
			if (memory == 0) {
				if (c + 1 < C)
					dfs(r, c + 1, 1);
				else
					dfs(r, 0, 1);
			} else {
				if (c - 1 >= 0)
					dfs(r, c - 1, 0);
				else
					dfs(r, C - 1, 0);
			}
		} else if (map[r][c] == '|') { // 메모리에 0이 저장되어 있으면 이동 방향을 아래쪽으로 바꾸고, 아니면 위쪽으로 바꾼다.
			if (memory == 0) {
				if (r + 1 < R)
					dfs(r + 1, c, 3);
				else
					dfs(0, c, 3);
			} else {
				if (r - 1 >= 0)
					dfs(r - 1, c, 2);
				else
					dfs(R - 1, c, 2);
			}
		} else if (map[r][c] == '?') { // 이동 방향을 상하좌우 중 하나로 무작위로 바꾼다. 방향이 바뀔 확률은 네 방향 동일하다.
			// 좌측
			if (c - 1 >= 0)
				dfs(r, c - 1, 0);
			else
				dfs(r, C - 1, 0);
			memory = tempMem;
			// 우측
			if (c + 1 < C)
				dfs(r, c + 1, 1);
			else
				dfs(r, 0, 1);
			memory = tempMem;
			// 상측
			if (r - 1 >= 0)
				dfs(r - 1, c, 2);
			else
				dfs(R - 1, c, 2);
			memory = tempMem;
			// 하측
			if (r + 1 < R)
				dfs(r + 1, c, 3);
			else
				dfs(0, c, 3);
			memory = tempMem;
		} else if (map[r][c] == '.') { // 아무 것도 하지 않는다.
			if (dir == 0) {
				if (c - 1 >= 0)
					dfs(r, c - 1, 0);
				else
					dfs(r, C - 1, 0);
			} else if (dir == 1) {
				if (c + 1 < C)
					dfs(r, c + 1, 1);
				else
					dfs(r, 0, 1);
			} else if (dir == 2) {
				if (r - 1 >= 0)
					dfs(r - 1, c, 2);
				else
					dfs(R - 1, c, 2);
			} else if (dir == 3) {
				if (r + 1 < R)
					dfs(r + 1, c, 3);
				else
					dfs(0, c, 3);
			}
		} else if (map[r][c] == '+') { // 메모리에 저장된 값에 1을 더한다. 만약 더하기 전 값이 15이라면 0으로 바꾼다.
			memory = (memory + 1) % 16;
			if (dir == 0) {
				if (c - 1 >= 0)
					dfs(r, c - 1, 0);
				else
					dfs(r, C - 1, 0);
			} else if (dir == 1) {
				if (c + 1 < C)
					dfs(r, c + 1, 1);
				else
					dfs(r, 0, 1);
			} else if (dir == 2) {
				if (r - 1 >= 0)
					dfs(r - 1, c, 2);
				else
					dfs(R - 1, c, 2);
			} else if (dir == 3) {
				if (r + 1 < R)
					dfs(r + 1, c, 3);
				else
					dfs(0, c, 3);
			}
		} else if (map[r][c] == '-') { // 메모리에 저장된 값에 1을 뺀다. 만약 빼기 전 값이 0이라면 15로 바꾼다.
			memory = (memory + 15) % 16;
			if (dir == 0) {
				if (c - 1 >= 0)
					dfs(r, c - 1, 0);
				else
					dfs(r, C - 1, 0);
			} else if (dir == 1) {
				if (c + 1 < C)
					dfs(r, c + 1, 1);
				else
					dfs(r, 0, 1);
			} else if (dir == 2) {
				if (r - 1 >= 0)
					dfs(r - 1, c, 2);
				else
					dfs(R - 1, c, 2);
			} else if (dir == 3) {
				if (r + 1 < R)
					dfs(r + 1, c, 3);
				else
					dfs(0, c, 3);
			}
		}
		memory = tempMem; // current memory recover
	}

}
