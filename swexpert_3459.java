package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 * ���̸� depth��� ���� ��, Alice�� depth�� Ȧ����° ������, Bob�� ¦����° ������ 2^depth <= x <
 * 2^(depth+1)�� ���ڸ� �� �� �ִ�.
 * 
 * �º��� ������ �Ǵ� ���� N�� �����ϴ� ���̿��� ������ �� �� �ִ����� ���� ������ ������ ������.
 * 
 * 
 * N�� 23�̶�� ���� ��, Bob�� �ش� ���̿��� 23������ ���ڸ� �� �� �ִ� ��� Bob�� �¸�, 23�� �ʰ��ϴ� ���ڸ��� ����
 * �Ǵ� ��� Alice�� �¸��̴�.
 * 
 * ���� ������ ���¿� ���� Alice�� �ڽ��� �� �� �ڽ��� �� �� �ִ� ���� ���� ū ���� ���� ���� �ּ�, Bob�� �ڽ��� �� ��
 * �ڽ��� �� �� �ִ� ���� ���� ���� ���� ���� ���� �ּ��̴�. x�� �ʱⰪ�� 1�̰� Alice�� ó�� �����ϴ� ���� �����Ͽ� ������
 * N�� 3������ ��Ȳ�� ����ó�� ���ش�. ex) N : 1�� ��, Bob �¸�, N : 2, 3�� ��, Alice �¸�
 * 
 * 
 * N�� ������ 10^18 �̹Ƿ�, 2^10�� 1024(�� 10^3)���� ����Ͽ� 2^60������ ��� �� �� �ִ�. ���� Ʈ���� depth
 * ũ�⿡ ���� �����ϱ⿡ O(log(N))�ν� �־��� ��Ȳ������ 60�����̰� �� 100ms�ȿ� ���� �� �ִ�.
 *
 */
public class swexpert_3459 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; ++tc) {
			long N = Long.parseLong(br.readLine());

			if (N <= 3) {
				if (N == 1) {
					bw.write("#" + tc + " Bob\n");
				}
				else {
					bw.write("#" + tc + " Alice\n");
				}
			}
			else {
				long A = 0;
				long B = 1;
				while(true) {
					A = ((A << 1) + 1) << 1; // A�� �̻��̸� Alice ��
					if(N < A) {
						bw.write("#" + tc + " Bob\n");
						break;
					}
					B = ((B << 1) + 1) << 1; // B�� �̻��̸� Bob ��
					if(N < B) {
						bw.write("#" + tc + " Alice\n");
						break;
					}
				}
			}
		}

		bw.flush();
		bw.close();
		br.close();
	}

}
