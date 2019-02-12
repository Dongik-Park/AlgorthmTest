package com.ssafy.exercise;

public class Backtracking_Permutation {
	public static int arr[] = { 3, 5, 8, 10 }; // power set�� ������ �迭
	/**
	 * 
	 * @param a     ���� ��� ���θ� üũ�� �迭
	 * @param k     ���� �ܰ�
	 * @param input �ܰ��� ������(������� ����)
	 * @param c     �ĺ����� ������ �迭
	 * @return ncands �ĺ��� ����
	 */
	private static int makeCandidate(int[] a, int k, int input, int[] c) {
		boolean inPerm[] = new boolean[a.length];
		
		for(int i = 0; i < k; ++i)
			inPerm[a[i]] = true;
		
		int ncands = 0;
		for(int i = 0; i < input; ++i)
			if(inPerm[i] == false) {
				c[ncands] = i;
				ncands++;
			}
		
		return ncands;
	} // end of makeCandidate

	/**
	 * �ϼ��� a �迭�� ���� �޾�, ���Ҹ� ������� Ȯ���ؼ� power set�� ���
	 * 
	 * @param a ���� ��� ���θ� üũ�� �迭
	 * @param k ���� �ܰ�
	 */
	private static void processSolution(int[] a, int k) {
		for (int i = 0; i < k; ++i) {
			System.out.print(arr[a[i]] + " "); // power set ���
		}
		System.out.println();
	} // end of processSolution

	/**
	 * 
	 * @param a     ���� ��� ���θ� üũ�� �迭
	 * @param k     ���� �ܰ�
	 * @param input �ܰ��� ������(������� ����)
	 */
	public static void backtracking(int a[], int k, final int input) {
		// end part
		if (k == input) {
			processSolution(a, k);// power set�� ����ϱ�
			return;
		}

		// recursive part
		int[] c = new int[a.length];
		int ncands = makeCandidate(a, k, input, c); // �ĺ��� �����
		for (int i = 0; i < ncands; ++i) {
			a[k] = c[i]; // ���� �ܰ��� �ĺ��� �ϳ��� �ִ´�.
			backtracking(a, k + 1, input); // ���� �ܰ踦 �����ϵ��� k + 1 �ܰ踦 ��� ȣ��
		}
	} // end of backtracking

	public static void main(String[] args) {
		int[] a = new int[arr.length]; // ������ ������ �迭

		backtracking(a, 0, a.length);
	} // end of main

} // end of class
