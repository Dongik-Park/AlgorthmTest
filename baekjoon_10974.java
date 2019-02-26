package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;

public class baekjoon_10974 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		Integer arr[] = new Integer[N];
		
		for(int i = 0; i < N; ++i)
			arr[i] = i + 1;
		
		Permutation2 perm = new Permutation2(arr); // 순열 객체 생성
		
		while(!perm.hasNextPermutation()) { // 순열 추출 
			for(Integer num : perm.nextPermutation())
				bw.write(num + " ");
			bw.write("\n");
		}
		// data output
		bw.flush();
		
		bw.close();
		br.close();
	}
}
class Permutation2 {
	private Queue<Integer[]> perm;
	private Integer arr[];
	/**
	 * 생성 및 permutation
	 * @param arr 순열 조합할 정렬된 배열
	 */
	public Permutation2(Integer arr[]) {
		this.arr = arr;
		perm = new ArrayDeque<>();
		Integer[] a = new Integer[arr.length]; // 순열을 index를 저장할 배열
		backtracking(a, 0, a.length);
	}
	/**
	 * 다음 순열 조합이 존재하는지 여부 반환
	 * @return 다음 순열 조합이 존재 여부
	 */
	public boolean hasNextPermutation() {
		return perm.isEmpty();
	}
	/**
	 * 다음 순열 조합을 추출하는 메소드
	 * @return 다음 순열 조합
	 */
	public Integer[] nextPermutation() {
		return perm.poll();
	}
	/**
	 * 
	 * @param a     원소 사용 여부를 체크할 배열
	 * @param k     현재 단계
	 * @param input 단계의 끝범위(변경되지 않음)
	 * @param c     후보군을 저장할 배열
	 * @return ncands 후보군 개수
	 */
	private int makeCandidate(Integer[] a, int k, int input, int[] c) {
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
	 * 
	 * @param a     원소 사용 여부를 체크할 배열
	 * @param k     현재 단계
	 * @param input 단계의 끝범위(변경되지 않음)
	 */
	public void backtracking(Integer a[], int k, final int input) {
		// end part
		if (k == input) {
			Integer[] cur = new Integer[k];
			for(int i = 0; i < k; ++i)
				cur[i] = arr[a[i]];
			perm.add(cur); // power set추가
			return;
		}

		// recursive part
		int[] c = new int[a.length];
		int ncands = makeCandidate(a, k, input, c); // 후보군 만들기
		for (int i = 0; i < ncands; ++i) {
			a[k] = c[i]; // 현재 단계의 후보군 하나를 넣는다.
			backtracking(a, k + 1, input); // 다음 단계를 진행하도록 k + 1 단계를 재귀 호출
		}
	} // end of backtracking
}