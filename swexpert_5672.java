package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class swexpert_5672 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; tc++) {
			// data input
			int N = Integer.parseInt(br.readLine().trim());
			char[] names = new char[N]; // �޹��� �̸� ����
			for (int i = 0; i < N; i++) {
				names[i] = br.readLine().trim().charAt(0);
			}

			// solve
			int head = 0; // �տ��� index
			int tail = N - 1; // �ڿ��� ���� index

			StringBuilder res = new StringBuilder();
			while (head <= tail) {
				if (head == tail) { // �߾ӿ� ����������
					res.append(names[head++]); // �߰��� ����
					break;
				} else if (names[head] == names[tail]) { // �� ���� ��ġ�� ���� ��� �߰��� �����ؾ���
					int nextHead = head;
					int nextTail = tail;
					while (names[nextHead] == names[nextTail]) { // ������ ���������� ����
						nextHead++;
						nextTail--;
						if (nextTail == nextHead) {
							res.append(names[head++]);
							break;
						} else if (names[nextHead] < names[nextTail]) { // ���� �ٸ� ������ ��� ���Ͽ� �ٱ��� while�� head �Ǵ� tail�� ����
							res.append(names[head++]);
							break;
						} else if (names[nextHead] > names[nextTail]) {
							res.append(names[tail--]);
							break;
						} else if (nextHead > nextTail) {
							res.append(names[head++]);
							break;
						}
					}
				} else if (names[head] < names[tail]) { // head�� ���� ���
					res.append(names[head++]);
				} else if (names[head] > names[tail]) { // tail�� ���� ���
					res.append(names[tail--]);
				}
			}
			
			// data output
			System.out.println("#" + tc + " " + res);
		} // end of test case
	} // end of main

} // end of class

 