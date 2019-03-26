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
			// ��ȭ��ȣ ����� �������� �����Ͽ� ������Ұ� �������ҿ� ���ԵǴ��� ���θ� Ȯ���Ѵ�.
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
