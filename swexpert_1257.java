package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.TreeSet;

public class swexpert_1257 {

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
		Set<String> sets = new TreeSet<>(new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				return o1.compareTo(o2);
			}
		});
		// add substring by ascending
		int cnt = 1;
		while(cnt != str.length() + 1) {
			for(int i = 0; i < str.length(); ++i) {
				if(i + cnt <= str.length())
					sets.add(str.substring(i, i + cnt));
			}
			++cnt;
		}
		// extract result
		String result = "none";
		int i = 0;
		for(String s : sets) {
			if(++i == n) {
				result = s;
				break;
			}
		}
		return result;
	}

}
