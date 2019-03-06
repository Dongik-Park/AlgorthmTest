package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class swexpert_3752 {
	static int N;
	static boolean score[];
	static int list[];
	static int res;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; ++tc) {
			N = Integer.parseInt(br.readLine());
			String s[] = br.readLine().split(" ");
			list = new int[N];
			
			int sum = 0;
			for (int i = 0; i < N; ++i) {
				list[i] = Integer.parseInt(s[i]);
				sum += list[i]; // ���� ������ �ִ����� �����Ѵ�.
			}

			score = new boolean[N * 100]; // ����� üũ�� �迭
			score[0] = true;
			
			for (int i = 0; i < N; i++) { 
				for (int j = sum; j >= 0; j--) { // �����պ��� 1�� �����Ѵ�.
					if (score[j]) { // ���簪�� üũ�Ǿ����� ���
						// bw.write(j + " checked => new check " + (j + list[i]) + "\n");
						score[j + list[i]] = true; // ���簪�� ���� ���� ��� ���� ���Ͽ� üũ�Ѵ�.
					}
				}
			}

			res = 0;
			for (int i = 0; i < score.length; ++i)
				if (score[i])
					++res;

			bw.write("#" + tc + " " + res + "\n");
		}

		bw.flush();
		bw.close();
		br.close();
	}

}
