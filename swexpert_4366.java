package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class swexpert_4366 {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; ++tc) {
			// data input
			String bin = br.readLine();
			String thr = br.readLine();
			
			// solve
			// 2������ �� �ڸ����� �����ϸ� �����Ѵ�.
			for(int i = 0; i < bin.length(); ++i) {
				StringBuilder temp = new StringBuilder(bin); // ������ų 2����
				int target = bin.length() - 1 - i; // �ڿ������� ����
				if(bin.charAt(target) == '0') { // 2������ ������Ų��.
					temp.setCharAt(target, '1');
				}
				else {
					temp.setCharAt(target, '0');
				}
				
				Long cur = Long.parseLong(temp.toString(), 2); // ���� 2������ �� ����
				String curThr = Long.toString(cur, 3); // ���� ���� 3������ ��ȯ
				
				if(thr.length() != curThr.length()) // ���� 3������ �ٸ� ��� �߰� ����
					continue;
				
				int cnt = 0;
				for(int j = 0; j < thr.length(); ++j) {
					 if(curThr.charAt(j) != thr.charAt(j)) {
						 ++cnt;
					 }
				}
				if(cnt == 1) {
					// data output
					System.out.println("#" + tc + " " + cur);
				}
				
			}
		}
	}
}
