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
			char[] names = new char[N]; // 앵무새 이름 저장
			for (int i = 0; i < N; i++) {
				names[i] = br.readLine().trim().charAt(0);
			}

			// solve
			int head = 0; // 앞에서 index
			int tail = N - 1; // 뒤에서 부터 index

			StringBuilder res = new StringBuilder();
			while (head <= tail) {
				if (head == tail) { // 중앙에 도달했을때
					res.append(names[head++]); // 중간값 삽입
					break;
				} else if (names[head] == names[tail]) { // 두 개의 위치가 같을 경우 추가로 진행해야함
					int nextHead = head;
					int nextTail = tail;
					while (names[nextHead] == names[nextTail]) { // 안쪽이 같을때까지 진행
						nextHead++;
						nextTail--;
						if (nextTail == nextHead) {
							res.append(names[head++]);
							break;
						} else if (names[nextHead] < names[nextTail]) { // 서로 다른 문자일 경우 비교하여 바깥쪽 while의 head 또는 tail을 삽입
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
				} else if (names[head] < names[tail]) { // head가 작을 경우
					res.append(names[head++]);
				} else if (names[head] > names[tail]) { // tail이 작을 경우
					res.append(names[tail--]);
				}
			}
			
			// data output
			System.out.println("#" + tc + " " + res);
		} // end of test case
	} // end of main

} // end of class

 