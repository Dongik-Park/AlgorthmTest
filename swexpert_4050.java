package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class swexpert_4050 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; ++tc) {
				// data input
				int N = Integer.parseInt(br.readLine().trim());
				StringTokenizer st = new StringTokenizer(br.readLine(), " ");
				PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						return o2 - o1;
					}
				});
				
				// solve
				// ������������ ����� �����Ͽ� 3�� ��� �ڸ��� ������ ���� ���� ���� ���� �� �ִ� �ִ� ����� ��
				int sum = 0;
				for(int i = 0; i < N; ++i) {
					int cur = Integer.parseInt(st.nextToken());
					pq.add(cur); // �������� ����
					sum += cur; // ��ü ���
				}
				
				int discount = 0;
				while(pq.size() >= 3) { 
					pq.remove();
					pq.remove();
					discount += pq.remove(); 
				}
	
				// data output
				StringBuilder builder = new StringBuilder();
				builder.append("#").append(tc).append(" ").append((sum - discount) + "");
				System.out.println(builder.toString());
		} // end of test case
		
		br.close();
	} // end of main
}
