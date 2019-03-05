package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Map;

public class swexpert_7206_2 {
	
	// Memoization set
	static boolean set[];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine());

		long t1 = 0l;
		for (int tc = 1; tc <= T; ++tc) {
			String N = br.readLine().trim();
			set = new boolean[99999];
			t1 = System.currentTimeMillis();
			bw.write("#" + tc + " " + f(Integer.parseInt(N)) + "\n");
		}
		System.out.println(System.currentTimeMillis() - t1);
		

		bw.flush();
		bw.close();
		br.close();
	}

	public static int f(int N) {
		if (N < 10) {
			return 0;
		}
		String s = "" + N;
		int len = s.length() - 1;

		int maxCnt = 0;
		for (int i = 1; i < 1 << len; ++i) { // 쪼갤 수 있는 모든 경우를 나누는 바이너리 카운팅
			//System.out.printf("%4s : ", Integer.toBinaryString(i));
			int num = s.charAt(0) - '0'; // 0번쨰 숫문자를 숫자로
			int mul = 1;
			for(int j = 0; j < len; ++j) {
				if((i & 1 << j) == 0) { // 쪼개지 않는 칸.
					num = num * 10 + s.charAt(j + 1) - '0';
				}
				else { // 쪼갬
					mul *= num;
					//System.out.print(num + ", ");
					num = s.charAt(j + 1) - '0';
				}
			}
			mul *= num;
			int cnt = 0;
			if(!set[mul])
				cnt = f(mul); // 많은 중복 발생
			set[mul] = true; // memoization
			maxCnt = Math.max(maxCnt, cnt);
			//System.out.println(num + " : " + mul);
		}

		return maxCnt + 1;
	}
}
