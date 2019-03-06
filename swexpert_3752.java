package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class swexpert_3752 {
	static int N;
	static boolean score[];
	static int list[];
	static int res;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; ++tc) {
			N = Integer.parseInt(br.readLine());
			String s[] = br.readLine().split(" ");
			list = new int[N];
			
			int sum = 0;
			for (int i = 0; i < N; ++i) {
				list[i] = Integer.parseInt(s[i]);
				sum += list[i]; // 들어온 점수의 최대합을 누적한다.
			}

			score = new boolean[N * 100]; // 결과를 체크할 배열
			score[0] = true;
			
			for (int i = 0; i < N; i++) { 
				for (int j = sum; j >= 0; j--) { // 누적합부터 1씩 감소한다.
					if (score[j]) { // 현재값이 체크되어있을 경우
						// bw.write(j + " checked => new check " + (j + list[i]) + "\n");
						score[j + list[i]] = true; // 현재값에 현재 점수 요소 값을 더하여 체크한다.
					}
				}
			}

			res = 0;
			for (int i = 0; i < score.length; ++i)
				if (score[i])
					++res;

			bw.write("#" + tc + " " + res + "\n");
		}

		bw.flush();
		bw.close();
		br.close();
	}

}
