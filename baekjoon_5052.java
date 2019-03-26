package com.ssafy.algo;

import java.util.Arrays;
import java.util.Scanner;

public class baekjoon_5052 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int tc = 1; tc <= T; ++tc) {
			// data input
			int N = sc.nextInt();
			String s[] = new String[N];
			for(int i = 0; i < N; ++i)
				s[i] = sc.next();
			
			// solve
			// 전화번호 목록을 오름차순 정렬하여 현재원소가 다음원소에 포함되는지 여부를 확인한다.
			// ex) 123, 1234, 13, 134...
			Arrays.sort(s);
			boolean res = true;
			for(int i = 0; i < s.length - 1; ++i) {
				if(s[i + 1].contains(s[i])) {
					res = false;
					break;
				}
			}
			
			// data output
			if(res) {
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
		}
	}

}
