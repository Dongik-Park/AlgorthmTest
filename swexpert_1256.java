package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;

public class swexpert_1256 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; ++tc) {
			// data input
			int N = Integer.parseInt(br.readLine());
			String str = br.readLine();
			// solve
			bw.write("#" + tc + " " + solve(N, str) + "\n");
		}
		// flush data
		bw.flush();
		bw.close();
		br.close();
	}

	private static String solve(int n, String str) {
		PriorityQueue<String> pq = new PriorityQueue<>();
		pq.add(str);
		// add substring by ascending
		for(int i = 1; i < str.length(); ++i) {
			pq.add(str.substring(i, str.length()));
		}
		// return n-th element
		for(int i = 0; i < n - 1; ++i)
			pq.poll();
		return pq.poll();
	}

}
