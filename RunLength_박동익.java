package com.ssafy.exercise;

public class RunLength_박동익 {
	static char compacted[] = new char[10000];
	static int idx;
	/**
	 * compacted된 문자열을 디코딩하여 출력하는 함수
	 */
	public static void RLDecoding() {
		for (int i = 0; i < idx; i += 2) {
			char cur = compacted[i];
			int cnt = compacted[i + 1];
			for (int j = 0; j < cnt; ++j)
				System.out.print(cur);
		}
	}
	/**
	 * Run length endcoding 함수 [ 문자 , 문자 개수, 문자, 문자 개수 ..]
	 * @param input 인코딩할 문자열
	 */
	public static void RLEncoding(String input) {
		int count = 0;
		char prev = input.charAt(0);
		char cur = '\0';
		for (int i = 0; i < input.length(); ++i) {
			cur = input.charAt(i);
			if (prev == cur) {
				++count;
			} else {
				System.out.println(prev + " " + count);
				compacted[idx++] = prev;
				compacted[idx++] = (char) count; // save result
				count = 1;
				prev = cur;
			}
		}
		System.out.println(cur + " " + count);
		compacted[idx++] = cur;
		compacted[idx++] = (char) count; // save result
	}

	/**
	 * 70% 확률로 알파벳 5~9개가 반복되는 길이 20~59의 문자열 생성 함수
	 * 
	 * @return 완성된 랜덤 문자열
	 */
	private static String getRandomRedundantString() {
		int len = (int) (Math.random() * 40 + 20);
		int kindNum = (int) (Math.random() * 5 + 5);
		StringBuilder sb = new StringBuilder(len);

		sb.append((char) ((Math.random() * kindNum) + 'A'));
		for (int i = 1; i < len; i++) {
			if (Math.random() > 0.7)
				sb.append((char) ((Math.random() * kindNum) + 'A'));
			else
				sb.append(sb.charAt(i - 1));
		}

		return sb.toString();
	}

	public static void main(String[] args) {
		String str = getRandomRedundantString();
		System.out.println(str + " 문자열 인코딩 시작");
		RLEncoding(str);
		System.out.println(str + " 문자열 디코딩 시작");
		RLDecoding();
	}
}
