package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class swexpert_3378 {

	private static String[] prr;
	private static String[] qrr;
	private static int[] result;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; ++tc) {
			int p, q;
			String ss[] = br.readLine().trim().split(" ");
			p = Integer.parseInt(ss[0]);
			q = Integer.parseInt(ss[1]);
			prr = new String[p]; // 마스터 코드
			qrr = new String[q]; // 유저 코드
			result = new int[q]; // 출력 결과를 저장할 배열

			Arrays.fill(result, -2); // 사용하지 않는 숫자로 초기화

			/*
			 * int R, C, S, a, b, c, d, e, f; R = C = S = a = b = c = d = e = f = 0;
			 */
			// 스타일리쉬 마스터의 글 입력
			for (int i = 0; i < p; ++i) {
				prr[i] = br.readLine();
			}
			// 당신의 스타일리쉬 글 입력
			for (int i = 0; i < q; ++i) {
				qrr[i] = br.readLine();
			}

			for (int r = 1; r <= 20; ++r) {
				for (int c = 1; c <= 20; ++c) {
					for (int s = 1; s <= 20; ++s) {
						if (isMasterCodePossible(r, c, s)) { // 마스터 코드의 모든 경우에 수 체크
							isUserCodePossible(r, c, s); // 유저의 모든 코드 행에서 가능한지 체크 후 배열에 저장
						}
					}
				}
			}

			// data output
			StringBuilder builder = new StringBuilder();
			builder.append("#").append(tc).append(" ");
			for (int i = 0; i < result.length; ++i)
				builder.append(result[i]).append(" ");
			System.out.println(builder.toString());
		} // end of test case

		br.close();
	} // end of main

	private static void isUserCodePossible(int r, int c, int s) {
		int rr = 0;
		int cc = 0;
		int ss = 0;
		for(int i = 0; i < qrr.length; ++i) {
			int res = r * rr + c * cc + s * ss; // 출력할 값
			if(result[i] == -2) // 처음 값을 저장하는 경우
				result[i] = res; 
			else if(result[i] >= 0 && result[i] != res) // 처음 저장하는 경우가 아니라면
				result[i] = -1; // 답이 여러개가 될 수 있는 경우
			
			String str = qrr[i];
			for(int j = 0; j < str.length(); ++j) {
				if      (str.charAt(j) == '(') ++rr;
				else if (str.charAt(j) == ')') --rr;
				else if (str.charAt(j) == '{') ++cc;
				else if (str.charAt(j) == '}') --cc;
				else if (str.charAt(j) == '[') ++ss;
				else if (str.charAt(j) == ']') --ss;
			}
			
		}
	}

	private static boolean isMasterCodePossible(int r, int c, int s) {
		int rr = 0; // ()의 개수
		int cc = 0; // {}
		int ss = 0; // []

		for (int i = 0; i < prr.length; ++i) {
			int dot = 0; // .의 개수
			String str = prr[i]; // 마스터 코드의 한줄
			int j;
			for (j = 0; j < str.length(); ++j) {
				if (str.charAt(j) == '.')
					++dot;
				else
					break; // 글자가 나오면 종료
			}
			
			if(r * rr + c * cc + s * ss != dot) // 모든 줄을 검사하던 중 한줄이라도 틀리면 거짓 반환
				return false;
			
			for (; j < str.length(); ++j) { // . 글자 다음 글자부터 검색
				if      (str.charAt(j) == '(') ++rr;
				else if (str.charAt(j) == ')') --rr;
				else if (str.charAt(j) == '{') ++cc;
				else if (str.charAt(j) == '}') --cc;
				else if (str.charAt(j) == '[') ++ss;
				else if (str.charAt(j) == ']') --ss;
			}
		}

		return true; // 모든 줄 검사를 통과한 경우
	}

}
