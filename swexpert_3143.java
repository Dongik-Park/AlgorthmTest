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
			
			int idx = 0; // A�� index
			int cnt = 0; // A�� �����ϴ� B substring ����
			
			while(idx < A.length()) { 
				int cur = A.indexOf(B, idx);
				if(cur == -1)
					break;
				idx = cur + B.length(); // idx���� A.length���� �� B substring�� �����ϴ� ��� idx ����
				++cnt;
			}
			
			System.out.println("#" + tc + " " + (A.length() - B.length() * cnt + cnt));
		}

		br.close();
	}

}
