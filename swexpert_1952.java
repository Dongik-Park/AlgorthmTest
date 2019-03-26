package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class swexpert_1952 {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; ++tc) {
			int []price = new int[4]; // 1일권, 1달권, 3달권, 1년권
			int []schedule = new int[13]; // 1 - 12월
			// data input
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			for(int i = 0; i < 4; ++i)
				price[i] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine().trim());
			for(int i = 1; i <= 12; ++i)
				schedule[i] = Integer.parseInt(st.nextToken());
			
			// solve
			int []dp = new int[13];
			for(int i = 1; i <= 12; ++i) {
				dp[i] = Math.min(price[0] * schedule[i], price[1]) + dp[i - 1]; // 하루치와 1달치 중
				if(i - 3 >= 0)
					dp[i] = Math.min(dp[i], dp[i - 3] + price[2]); // 3달전 값과 비교
			}
			dp[12] = Math.min(dp[12], price[3]);
			
			// data output
			bw.write("#" + tc + " " + dp[12] + "\n");
		}
		
		bw.flush();
		bw.close();
		br.close();
	}

}
