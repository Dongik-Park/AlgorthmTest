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
		
		Permutation2 perm = new Permutation2(arr); // ���� ��ü ����
		
		while(!perm.hasNextPermutation()) { // ���� ���� 
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
	 * ���� �� permutation
	 * @param arr ���� ������ ���ĵ� �迭
	 */
	public Permutation2(Integer arr[]) {
		this.arr = arr;
		perm = new ArrayDeque<>();
		Integer[] a = new Integer[arr.length]; // ������ index�� ������ �迭
		backtracking(a, 0, a.length);
	}
	/**
	 * ���� ���� ������ �����ϴ��� ���� ��ȯ
	 * @return ���� ���� ������ ���� ����
	 */
	public boolean hasNextPermutation() {
		return perm.isEmpty();
	}
	/**
	 * ���� ���� ������ �����ϴ� �޼ҵ�
	 * @return ���� ���� ����
	 */
	public Integer[] nextPermutation() {
		return perm.poll();
	}
	/**
	 * 
	 * @param a     ���� ��� ���θ� üũ�� �迭
	 * @param k     ���� �ܰ�
	 * @param input �ܰ��� ������(������� ����)
	 * @param c     �ĺ����� ������ �迭
	 * @return ncands �ĺ��� ����
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
	 * @param a     ���� ��� ���θ� üũ�� �迭
	 * @param k     ���� �ܰ�
	 * @param input �ܰ��� ������(������� ����)
	 */
	public void backtracking(Integer a[], int k, final int input) {
		// end part
		if (k == input) {
			Integer[] cur = new Integer[k];
			for(int i = 0; i < k; ++i)
				cur[i] = arr[a[i]];
			perm.add(cur); // power set�߰�
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
}