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
			// 2진수의 각 자리수를 반전하며 진행한다.
			for(int i = 0; i < bin.length(); ++i) {
				StringBuilder temp = new StringBuilder(bin); // 반전시킬 2진수
				int target = bin.length() - 1 - i; // 뒤에서부터 진행
				if(bin.charAt(target) == '0') { // 2진수를 반전시킨다.
					temp.setCharAt(target, '1');
				}
				else {
					temp.setCharAt(target, '0');
				}
				
				Long cur = Long.parseLong(temp.toString(), 2); // 현재 2진수의 값 추출
				String curThr = Long.toString(cur, 3); // 현재 값을 3진수로 변환
				
				if(thr.length() != curThr.length()) // 비교할 3진수가 다를 경우 추가 진행
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
