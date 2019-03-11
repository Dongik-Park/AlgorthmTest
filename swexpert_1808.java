package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class swexpert_1808 {

	private static boolean chk[]; // 현재 숫자 포함 여부

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; ++tc) {
			// data input
			String s[] = br.readLine().trim().split(" ");
			chk = new boolean[10];
			for (int i = 0; i < 10; ++i) {
				if (Integer.parseInt(s[i]) == 1) {
					chk[i] = true;
				}
			}
			// solve
			int X = Integer.parseInt(br.readLine().trim());
			int res2 = solve2(X);
			
			//data output
			System.out.println("#" + tc + " " + (res2 == -1 ? -1 : res2 + 1));
		}

	}

	private static int solve2(int X) {
		//  System.out.println(X + "진행중");
		int res = Integer.MAX_VALUE;
		for (int i = 2; i * i <= X; ++i) {
			if (X % i == 0) { // X가 현재 숫자로 나누어 떨어질 경우
				int cur = isPossible(i); // 1의 자리수가 클릭 가능할 경우
				if (cur != -1) { 
					int next = solve2(X / i); // 숫자를 나누어 다시 진행한다.
					if (next != -1) { // 끝까지 진행하였을 때 1의 자리수가 클릭이 가능하여 클릭한 누적 횟수값이 -1이 아닐 경우
						res = (res > (next + cur + 1)) ? (cur + next + 1) : res;
					}
				}
			}
		}

		int a = isPossible(X); // 1의 자리수가 클릭 가능한지 확인

		if (res == Integer.MAX_VALUE) { // 위에서 데이터를 못찾은 경우 1의 자리수확인
			return (a != -1) ? a : -1;
		} else // 위의 반복문에서 데이터를 찾은 경우 한번에 클릭되는 지 여부 확인
			return (a != -1 && a < res) ? a : res;
	}

	private static int isPossible(int num) {
		if (num < 10)
			return chk[num] ? 1 : -1;
		else {
			if (chk[num % 10]) { // 1의 자리수를 검사하여 입력가능할 경우
				int next = isPossible(num / 10); // 10을 나눈 수로 진행한다.
				return next == -1 ? -1 : next + 1; // 최종적으로 입력 가능할 경우 -1이 아니고, 여기에 나눈 횟수를 추가하여 반환
			} else
				return -1;
		}
	}
}
