package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;

public class baekjoon_9375 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; ++tc) {
			int N = Integer.parseInt(br.readLine());

			Map<String, Integer> map = new HashMap<>();
			for (int i = 0; i < N; ++i) {
				String cur = br.readLine();
				String curs[] = cur.split(" ");

				if (map.containsKey(curs[1])) {
					map.put(curs[1], map.get(curs[1]) + 1);
				} else {
					map.put(curs[1], 1);
				}
			}
			
			int sum = 1;
			for (int y : map.values()) {
				sum *= y + 1;
			}
			
			bw.write(sum - 1 + "\n");
		}
		bw.flush();
		
		br.close();
		bw.close();
	}
}
