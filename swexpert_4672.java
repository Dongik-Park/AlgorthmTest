package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class swexpert_4672 {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		
		for(int tc = 1; tc <= T; ++tc) {
			String s = br.readLine();
			
			// ���ĺ��� ������ ����� ����.
			int alphapet[] = new int[26];
			for(int i = 0; i < s.length(); ++i)
				alphapet[s.charAt(i) - 'a']++;
			// ���ĺ� ������ŭ �߰� ����
			int res = 0;
			for(int i = 0; i < alphapet.length; ++i)
				if(alphapet[i] > 0)
					res += alphapet[i];
			// ��ȭ�� (n * (n - 1) / 2) ������ŭ �߰� ���� 
			// ex) ccc => cc cc ccc - 3��
			//     cccc => cc cc cc ccc ccc cccc - 6��
			for(int i = 0; i < alphapet.length; ++i) {
				if(alphapet[i] > 1) {
					int n = alphapet[i];
					res += (n * (n - 1)) / 2;
				}
			}
			
			System.out.println("#" + tc + " " + res);
		}
		
	}
	
	private static boolean isPelindrom(String s) {
		if(s.length() == 1)
			return true;
		StringBuilder sb = new StringBuilder();
		// Ȧ���� ���
		if((s.length() & 1) == 1) {
			sb.append(s.substring(0, s.length() / 2));
			sb.append(s.substring(s.length() / 2 + 1, s.length()));
		}
		// ¦���� ���
		else {
			sb.append(s);
		}
		if(sb.toString().equals(sb.reverse().toString()))
			return true;
		return false;
	}

}
