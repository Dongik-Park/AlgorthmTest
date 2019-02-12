package com.ssafy.exercise;

public class Backtracking_Powerset {
	public static int arr[] = { 3, 5, 8, 10 }; // power set�� ������ �迭
	/**
	 * 
	 * @param a     ���� ��� ���θ� üũ�� �迭
	 * @param k     ���� �ܰ�
	 * @param input �ܰ��� ������(������� ����)
	 * @param c     �ĺ����� ������ �迭
	 * @return ncands �ĺ��� ����
	 */
	private static int makeCandidate(boolean[] a, int k, int input, boolean[] c) {
		c[0] = true;
		c[1] = false;
		return 2;
	} // end of makeCandidate

	/**
	 * �ϼ��� a �迭�� ���� �޾�, ���Ҹ� ������� Ȯ���ؼ� power set�� ���
	 * 
	 * @param a ���� ��� ���θ� üũ�� �迭
	 * @param k ���� �ܰ�
	 */
	private static void processSolution(boolean[] a, int k) {
		for (int i = 0; i < a.length; ++i) {
			if (a[i])
				System.out.print(arr[i] + " "); // power set ���
		}
		System.out.println();
	} // end of processSolution

	/**
	 * 
	 * @param a     ���� ��� ���θ� üũ�� �迭
	 * @param k     ���� �ܰ�
	 * @param input �ܰ��� ������(������� ����)
	 */
	public static void backtracking(boolean a[], int k, final int input) {
		// end part
		if (k == input) {
			processSolution(a, k);// power set�� ����ϱ�
			return;
		}

		// recursive part
		boolean[] c = new boolean[a.length];
		int ncands = makeCandidate(a, k, input, c); // �ĺ��� �����
		for (int i = 0; i < ncands; ++i) {
			a[k] = c[i]; // ���� �ܰ��� �ĺ��� �ϳ��� �ִ´�.
			backtracking(a, k + 1, input); // ���� �ܰ踦 �����ϵ��� k + 1 �ܰ踦 ��� ȣ��
		}
	} // end of backtracking

	public static void main(String[] args) {
		boolean[] check = new boolean[arr.length]; // ���� ��� ���� üũ �迭

		backtracking(check, 0, check.length);
	} // end of main

} // end of class
