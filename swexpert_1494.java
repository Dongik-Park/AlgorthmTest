package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 * 지렁이 개수 = 짝수개, 둘씩 짝궁을 지어준다. 짝을 지어주는 모든 경우의 수를 새악해보고, 가각의 짝이 연결되는 벡터를 구해서, 벡터들의
 * 전체 합을 구한 뒤, 벡터 전체합의 크기를 구한다. 이렇게 만든 벡터전체합의 최소값을 찾는 문제
 * 
 * 팁 : 벡터상의 출발위치에 있는 지렁이 좌표의 합 - 벡터 상의 도착위치에 있는 지럴이 좌표의 합 = 벡터 전체의 합 그러므로 출발 위치
 * 지렁이 끼리는 변경되더라도 벡터 전체의 합은 동일하다. 도착 위치 지렁이 끼리는 변경되더라도 벡터 전체의 합은 동일하다. 결국, 출발위치의
 * 그룹, 도착위치의 그룹으로 분할하는 문제 = 출발위치에 올 수 있는 N / 2마리 지렁이를 선택하는 조합문제
 * 
 * 1번 방법 : 순수 조합문제로 조합이 완성되었을 때, 좌표들의 합을 구해서, 벡터 크기의 최소값을 업데이트한다. 2번 방법 : 조합을
 * 재귀호출시 지렁이의 선택여부에 따라 좌표들의 합을 매개변수로 전달한다.(효율적)
 *
 */
public class swexpert_1494 {
	static int N;
	static final int MAX_N = 20;
	static int sumX, sumY; // 지렁이 원소의 합
	static int m[][]; // 지렁이의 위치
	static long result; // 전체 벡터합의 최소값

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

	private static void combo(int n, int r, int sX, int sY) { // 선택한 지렁이의 조합
		// 종료 파트
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
		// 재귀 파트
		combo(n - 1, r - 1, sX + m[n - 1][0], sY + m[n - 1][1]); // 현재를 선택한 경우
		combo(n - 1, r, sX, sY); // 현재를 선택하지 않은 경우
	}
}