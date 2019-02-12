package com.ssafy.exercise;

public class Backtracking_Powerset {
	public static int arr[] = { 3, 5, 8, 10 }; // power set을 저장할 배열
	/**
	 * 
	 * @param a     원소 사용 여부를 체크할 배열
	 * @param k     현재 단계
	 * @param input 단계의 끝범위(변경되지 않음)
	 * @param c     후보군을 저장할 배열
	 * @return ncands 후보군 개수
	 */
	private static int makeCandidate(boolean[] a, int k, int input, boolean[] c) {
		c[0] = true;
		c[1] = false;
		return 2;
	} // end of makeCandidate

	/**
	 * 완성된 a 배열을 전달 받아, 원소를 출력할지 확인해서 power set을 출력
	 * 
	 * @param a 원소 사용 여부를 체크할 배열
	 * @param k 현재 단계
	 */
	private static void processSolution(boolean[] a, int k) {
		for (int i = 0; i < a.length; ++i) {
			if (a[i])
				System.out.print(arr[i] + " "); // power set 출력
		}
		System.out.println();
	} // end of processSolution

	/**
	 * 
	 * @param a     원소 사용 여부를 체크할 배열
	 * @param k     현재 단계
	 * @param input 단계의 끝범위(변경되지 않음)
	 */
	public static void backtracking(boolean a[], int k, final int input) {
		// end part
		if (k == input) {
			processSolution(a, k);// power set을 출력하기
			return;
		}

		// recursive part
		boolean[] c = new boolean[a.length];
		int ncands = makeCandidate(a, k, input, c); // 후보군 만들기
		for (int i = 0; i < ncands; ++i) {
			a[k] = c[i]; // 현재 단계의 후보군 하나를 넣는다.
			backtracking(a, k + 1, input); // 다음 단계를 진행하도록 k + 1 단계를 재귀 호출
		}
	} // end of backtracking

	public static void main(String[] args) {
		boolean[] check = new boolean[arr.length]; // 원소 사용 여부 체크 배열

		backtracking(check, 0, check.length);
	} // end of main

} // end of class
