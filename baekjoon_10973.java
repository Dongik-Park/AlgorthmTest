package com.ssafy.algo;

import java.util.Scanner;

public class baekjoon_10973 {
	// 순열을 사전순으로 나열했을 때, 사전순으로 다음에 오는 순열과 이전에 오는 순열을 찾을 수 있다.
	// 1. A[i-1] < A[i]를 만족하는 가장 큰 i를 찾는다
    // 2. j >= i 이면서 A[j] > A[i-1]를 만족하는 가장 큰 j를 찾는다.
    // 3. A[i-1]과 A[j]를 swap한다
    // 4. A[i]부터 순열을 뒤집는다
	// 참고 : https://appree.tistory.com/3?category=710893
	public static boolean nextPermutation(int[] a) {
		int i = a.length - 1;
		// 뒤에서부터 큰 값이 되는 지점을 찾는다. ( swap point )
		while (i > 0 && a[i - 1] <= a[i]) { 
			i -= 1;
		}

		// i가 0이하일 경우 내림차순으로 정렬된 것이므로 마지막 순열
		if (i <= 0) {
			return false;
		}

		int j = a.length - 1; // 가장 끝번째 index로 초기화
		while (a[j] >= a[i - 1]) { 
			j -= 1;
		}
		
		// swap
		int temp = a[i - 1];
		a[i - 1] = a[j];
		a[j] = temp;

		j = a.length - 1;
		while (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i += 1;
			j -= 1;
		}
		return true;
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		if (nextPermutation(a)) {
			for (int i = 0; i < n; i++) {
				System.out.print(a[i] + " ");
			}
			System.out.println();
		} else {
			System.out.println("-1");
		}
	}

}