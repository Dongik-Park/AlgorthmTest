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
		// ������ �Ȱ��� ����� Ű�� ������ ��� NO
		for (int i = 0; i < keyList[r][c].key.size(); ++i) {
			if (keyList[r][c].key.get(i).equals(memory + "" + dir + "")) {
				res = "NO";
				return;
			}
		}
		// ���� �̵� Ű �߰�
		keyList[r][c].key.add(memory + "" + dir + "");
		int tempMem = memory;

		if (map[r][c] == '@') { // ���� ����
			res = "YES";
			return;
		}
		else if (map[r][c] >= '0' && map[r][c] <= '9') { // ������ ���
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
		} else if (map[r][c] == '<') { // ������ ���
			if (c - 1 >= 0)
				dfs(r, c - 1, 0);
			else
				dfs(r, C - 1, 0);
		} else if (map[r][c] == '>') { // ������ ���
			if (c + 1 < C)
				dfs(r, c + 1, 1);
			else
				dfs(r, 0, 1);
		} else if (map[r][c] == '^') { // ������ ���
			if (r - 1 >= 0)
				dfs(r - 1, c, 2);
			else
				dfs(R - 1, c, 2);
		} else if (map[r][c] == 'v') { // ������ ���
			if (r + 1 < R)
				dfs(r + 1, c, 3);
			else
				dfs(0, c, 3);
		} else if (map[r][c] == '_') { // �޸𸮿� 0�� ����Ǿ� ������ �̵� ������ ���������� �ٲٰ�, �ƴϸ� �������� �ٲ۴�.
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
		} else if (map[r][c] == '|') { // �޸𸮿� 0�� ����Ǿ� ������ �̵� ������ �Ʒ������� �ٲٰ�, �ƴϸ� �������� �ٲ۴�.
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
		} else if (map[r][c] == '?') { // �̵� ������ �����¿� �� �ϳ��� �������� �ٲ۴�. ������ �ٲ� Ȯ���� �� ���� �����ϴ�.
			// ����
			if (c - 1 >= 0)
				dfs(r, c - 1, 0);
			else
				dfs(r, C - 1, 0);
			memory = tempMem;
			// ����
			if (c + 1 < C)
				dfs(r, c + 1, 1);
			else
				dfs(r, 0, 1);
			memory = tempMem;
			// ����
			if (r - 1 >= 0)
				dfs(r - 1, c, 2);
			else
				dfs(R - 1, c, 2);
			memory = tempMem;
			// ����
			if (r + 1 < R)
				dfs(r + 1, c, 3);
			else
				dfs(0, c, 3);
			memory = tempMem;
		} else if (map[r][c] == '.') { // �ƹ� �͵� ���� �ʴ´�.
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
		} else if (map[r][c] == '+') { // �޸𸮿� ����� ���� 1�� ���Ѵ�. ���� ���ϱ� �� ���� 15�̶�� 0���� �ٲ۴�.
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
		} else if (map[r][c] == '-') { // �޸𸮿� ����� ���� 1�� ����. ���� ���� �� ���� 0�̶�� 15�� �ٲ۴�.
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
