
public class Backtracking_Permutation {
	public static int arr[] = { 3, 5, 8, 10 }; 
	/**
	 * 
	 * @param a     순열의 index를 저장할 배열
	 * @param k     현재 단계
	 * @param input 단계의 끝범위(변경되지 않음)
	 * @param c     후보군을 저장할 배열
	 * @return ncands 후보군 개수
	 */
	private static int makeCandidate(int[] a, int k, int input, int[] c) {
		boolean inPerm[] = new boolean[input]; // 이미 전 단계에서 사용된 숫자를 체크할 flag 배열

		for (int i = 0; i < k; ++i) // 현재 단계 이전까지 사용한 숫자만 체크
			inPerm[a[i]] = true;

		int ncands = 0;
		for (int i = 0; i < input; ++i)
			if (inPerm[i] == false) {
				c[ncands] = i;
				ncands++;
			}

		return ncands;
	} // end of makeCandidate

	/**
	 * 조합이 완성된 a 배열을 전달 받아, 원소를 출력할지 확인해서 permutation을 출력
	 * 
	 * @param a 조합이 완성된 a 배열
	 * @param k 현재 단계
	 */
	private static void processSolution(int[] a, int k) {
		for (int i = 0; i < k; ++i) {
			System.out.print(arr[a[i]] + " "); // permutation 출력
		}
		System.out.println();
	} // end of processSolution

	/**
	 * 
	 * @param a     순열의 index를 저장할 배열
	 * @param k     현재 단계
	 * @param input 단계의 끝범위(변경되지 않음)
	 */
	public static void backtracking(int a[], int k, final int input) {
		// end part
		if (k == input) {
			processSolution(a, k);// power set을 출력하기
			return;
		}

		// recursive part
		int[] c = new int[a.length]; // 후보군을 저장할 배열
		int ncands = makeCandidate(a, k, input, c); // 후보군 만들기
		for (int i = 0; i < ncands; ++i) {
			a[k] = c[i]; // 현재 단계의 후보군 하나를 넣는다.
			backtracking(a, k + 1, input); // 다음 단계를 진행하도록 k + 1 단계를 재귀 호출
		}
	} // end of backtracking

	public static void main(String[] args) {
		int[] a = new int[arr.length]; // 순열의 index를 저장할 배열

		backtracking(a, 0, a.length);
	} // end of main

} // end of class
