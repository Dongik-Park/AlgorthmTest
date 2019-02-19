package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class baekjoon_7785 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		Set<String> sets = new TreeSet<>(new Comparator<String>() { 
			// 문자열 내림차순으로 정렬하기 위한 TreeSet
			@Override
			public int compare(String o1, String o2) {
				return o2.compareTo(o1);
			}
		});
		
		for(int tc = 1; tc <= T; ++tc) {
			StringTokenizer token = new StringTokenizer(br.readLine());
			String name = token.nextToken();
			String state = token.nextToken();
			if(state.equals("enter")) {
				sets.add(name);
			}
			else {
				sets.remove(name);
			}			
		}
		// 출력
		for(String s : sets) {
			System.out.println(s);
		}
	}
}
