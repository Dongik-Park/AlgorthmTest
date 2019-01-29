package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swexpert_1233 {
	static int[] arr = new int[256];
	static int N;
	public static int inorderTraverse(int t) {
		if (arr[t] == -1) { // 현재가 연산자일 경우
			int left = 0;
			int right = 0;
			
			if (t * 2 < arr.length)
				left = inorderTraverse(t * 2);
			if(left == 0)
				return 0;
			
			if (t * 2 + 1 < arr.length)
				right = inorderTraverse(t * 2 + 1);
			if(right == 0)
				return 0;
			
			return left + right;
		}
		else { // 숫자일 경우 자식이 존재하면 0값 반환
			if (t * 2 < arr.length && arr[t * 2] != 0)
				return 0;
			if (t * 2 + 1 < arr.length && arr[t * 2 + 1] != 0)
				return 0;
			return 1;
		}
	}

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int tc = 1; tc <= 10; ++tc) {
			N = Integer.parseInt(br.readLine());
			arr = new int[256];
			arr[1] = 1;
			boolean flag = true;
			
			// data input
			for(int i = 0; i < N; ++i) {
				StringTokenizer token = new StringTokenizer(br.readLine(), " ");
				
				if(token.countTokens() == 4) {
					int index = Integer.parseInt(token.nextToken());
					try {
						Integer.parseInt(token.nextToken()); // 만약 부모노드가 숫자일 경우 불가능한 연산
						flag = false;
					}
					catch (NumberFormatException e) {
						arr[index] = -1; // 숫자가 아닌 연산자일 경우
					}
					arr[index * 2] = Integer.parseInt(token.nextToken());
					arr[index * 2 + 1] = Integer.parseInt(token.nextToken());
				}
				else {
					int index = Integer.parseInt(token.nextToken());
					try {
						int val = Integer.parseInt(token.nextToken());
						arr[index] = val;
					}
					catch (NumberFormatException e) {
						arr[index] = -1; // 숫자가 아닌 연산자일 경우
					}
				}
			}
			int result = 0;
			if(flag)
				result = inorderTraverse(1);
			if(result != 0)
				result = 1;
			System.out.println("#" + tc + " " + result );
		}
		
	}
}
