package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 * 깊이를 depth라고 했을 때, Alice는 depth가 홀수번째 순서고, Bob은 짝수번째 순서로 2^depth <= x <
 * 2^(depth+1)의 숫자를 고를 수 있다.
 * 
 * 승부의 기준이 되는 숫자 N을 포함하는 깊이에서 무엇을 고를 수 있는지에 따라 정답의 유무가 갈린다.
 * 
 * 
 * N이 23이라고 했을 때, Bob이 해당 깊이에서 23이하의 숫자를 고를 수 있는 경우 Bob의 승리, 23을 초과하는 숫자만을 고르게
 * 되는 경우 Alice의 승리이다.
 * 
 * 최종 깊이의 상태에 따라 Alice는 자신의 턴 때 자신이 고를 수 있는 수의 가장 큰 수를 고르는 것이 최선, Bob은 자신의 턴 때
 * 자신이 고를 수 있는 수의 가장 작은 수를 고르는 것이 최선이다. x의 초기값은 1이고 Alice가 처음 시작하는 것을 감안하여 때문에
 * N이 3이하인 상황은 예외처리 해준다. ex) N : 1일 때, Bob 승리, N : 2, 3일 때, Alice 승리
 * 
 * 
 * N의 제한이 10^18 이므로, 2^10가 1024(약 10^3)임을 고려하여 2^60안으로 들어 올 수 있다. 이진 트리의 depth
 * 크기에 맞춰 실행하기에 O(log(N))로써 최악의 상황에서도 60이하이고 약 100ms안에 들어올 수 있다.
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
					A = ((A << 1) + 1) << 1; // A값 이상이면 Alice 승
					if(N < A) {
						bw.write("#" + tc + " Bob\n");
						break;
					}
					B = ((B << 1) + 1) << 1; // B값 이상이면 Bob 승
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
