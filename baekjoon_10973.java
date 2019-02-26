package com.ssafy.algo;

import java.util.Scanner;

public class baekjoon_10973 {
	// ������ ���������� �������� ��, ���������� ������ ���� ������ ������ ���� ������ ã�� �� �ִ�.
	// 1. A[i-1] < A[i]�� �����ϴ� ���� ū i�� ã�´�
    // 2. j >= i �̸鼭 A[j] > A[i-1]�� �����ϴ� ���� ū j�� ã�´�.
    // 3. A[i-1]�� A[j]�� swap�Ѵ�
    // 4. A[i]���� ������ �����´�
	// ���� : https://appree.tistory.com/3?category=710893
	public static boolean nextPermutation(int[] a) {
		int i = a.length - 1;
		// �ڿ������� ū ���� �Ǵ� ������ ã�´�. ( swap point )
		while (i > 0 && a[i - 1] <= a[i]) { 
			i -= 1;
		}

		// i�� 0������ ��� ������������ ���ĵ� ���̹Ƿ� ������ ����
		if (i <= 0) {
			return false;
		}

		int j = a.length - 1; // ���� ����° index�� �ʱ�ȭ
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