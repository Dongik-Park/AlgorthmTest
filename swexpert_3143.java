package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class swexpert_3143 {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; ++tc) {
			String s[] = br.readLine().trim().split(" ");
			String A = s[0];
			String B = s[1];
			
			int idx = 0; // A의 index
			int cnt = 0; // A에 존재하는 B substring 개수
			
			while(idx < A.length()) { 
				int cur = A.indexOf(B, idx);
				if(cur == -1)
					break;
				idx = cur + B.length(); // idx부터 A.length까지 중 B substring이 존재하는 경우 idx 갱신
				++cnt;
			}
			
			System.out.println("#" + tc + " " + (A.length() - B.length() * cnt + cnt));
		}

		br.close();
	}

}
