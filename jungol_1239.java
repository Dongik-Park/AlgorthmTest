package com.ssafy.algo;

import java.util.Scanner;

public class jungol_1239 {
	
	static String list[] = {
		"000000", // A
		"001111", // B
		"010011", // C
		"011100", // D
		"100110", // E
		"101001", // F
		"110101", // G
		"111010"  // H
	};
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(); sc.nextLine();
		String s = sc.nextLine();
		StringBuilder sb = new StringBuilder();
		
		for(int i = 0; i < s.length(); i += 6) {
			boolean flag = false;
			// A - H �� ��ġ�ϴ� ���� �ִ� �� �˻�
			for(int j = 0; j < list.length; ++j) {
				int cnt = 0;
				for(int k = 0; k < list[j].length(); ++k) { // ��ġ�ϴ� ���� ���� ī����
					if(list[j].charAt(k) == s.charAt(i + k))
						++cnt;
				}
				// ��ġ�ϴ� ���ĺ��� ���� ���
				if(cnt >= 5) {
					flag = true;
					sb.append((char)('A' + j) + "");
					break;
				}
			}
			// ��ġ�ϴ� ���ĺ��� ���� ���
			if(!flag) {
				System.out.println((i / 6 + 1) + "");
				return;
			}
		}
		// ���ĺ��� ���� ��� ���
		System.out.println(sb.toString());
	}
}
