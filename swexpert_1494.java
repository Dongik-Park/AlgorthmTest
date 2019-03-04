package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 * ������ ���� = ¦����, �Ѿ� ¦���� �����ش�. ¦�� �����ִ� ��� ����� ���� �����غ���, ������ ¦�� ����Ǵ� ���͸� ���ؼ�, ���͵���
 * ��ü ���� ���� ��, ���� ��ü���� ũ�⸦ ���Ѵ�. �̷��� ���� ������ü���� �ּҰ��� ã�� ����
 * 
 * �� : ���ͻ��� �����ġ�� �ִ� ������ ��ǥ�� �� - ���� ���� ������ġ�� �ִ� ������ ��ǥ�� �� = ���� ��ü�� �� �׷��Ƿ� ��� ��ġ
 * ������ ������ ����Ǵ��� ���� ��ü�� ���� �����ϴ�. ���� ��ġ ������ ������ ����Ǵ��� ���� ��ü�� ���� �����ϴ�. �ᱹ, �����ġ��
 * �׷�, ������ġ�� �׷����� �����ϴ� ���� = �����ġ�� �� �� �ִ� N / 2���� �����̸� �����ϴ� ���չ���
 * 
 * 1�� ��� : ���� ���չ����� ������ �ϼ��Ǿ��� ��, ��ǥ���� ���� ���ؼ�, ���� ũ���� �ּҰ��� ������Ʈ�Ѵ�. 2�� ��� : ������
 * ���ȣ��� �������� ���ÿ��ο� ���� ��ǥ���� ���� �Ű������� �����Ѵ�.(ȿ����)
 *
 */
public class swexpert_1494 {
	static int N;
	static final int MAX_N = 20;
	static int sumX, sumY; // ������ ������ ��
	static int m[][]; // �������� ��ġ
	static long result; // ��ü �������� �ּҰ�

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; ++tc) {
			// data input
			N = Integer.parseInt(br.readLine());
			m = new int[N][2];
			sumX = sumY = 0;
			for (int i = 0; i < N; ++i) {
				String s[] = br.readLine().trim().split(" ");
				m[i][0] = Integer.parseInt(s[0]);
				m[i][1] = Integer.parseInt(s[1]);
				sumX += m[i][0];
				sumY += m[i][1];
			}
			// solve
			result = Long.MAX_VALUE;
			combo(N, N / 2, 0, 0); // nCr(n, r, sumX, sumY);

			// data output
			bw.write("#" + tc + " " + result + "\n");
		}

		bw.flush();
		bw.close();
		br.close();
	}

	private static void combo(int n, int r, int sX, int sY) { // ������ �������� ����
		// ���� ��Ʈ
		if(n < r) {
			return;
		}
		else if(r == 0) {
			int sumUnSelectedX = sumX - sX;
			int sumUnSelectedY = sumY - sY;
			long vX = sX - sumUnSelectedX;
			long vY = sY - sumUnSelectedY;
			result = Math.min(result, vX * vX + vY * vY);
			return;
		}
		// ��� ��Ʈ
		combo(n - 1, r - 1, sX + m[n - 1][0], sY + m[n - 1][1]); // ���縦 ������ ���
		combo(n - 1, r, sX, sY); // ���縦 �������� ���� ���
	}
}