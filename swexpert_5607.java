import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/**
 * 구하려는 수 1234567891이 소수이기 때문에 페르마의 소정리를 이용해서 구할 수 있다.
 * a와 m이 서로소일 때, a^(m-1)을 m으로 나눈 나머지는 1이다.
 * 따라서 역원(=1234567891로 나눈 나머지)가 되기 위한 조건은 a^(m-2)이다.	
 * @author student
 *
 */
public class swexpert_5607 {
	static int N;
	static int R;
	
	public static long mul(long x, long y, long p) {
		long ans = 1;
		while (y > 0) {
			if (y % 2 != 0) {
				ans *= x;
				ans %= p;
			}
			x *= x;
			x %= p;
			y /= 2;
		}
		return ans;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder builder = new StringBuilder();
		int T;
		T = Integer.parseInt(br.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer token = new StringTokenizer(br.readLine());
			N = Integer.parseInt(token.nextToken());
			R = Integer.parseInt(token.nextToken());

			int p = 1234567891; // 나누고자 하는 수 = a

			long ans = 1;
			long t1 = 1;
			long t2 = 1;
			for (long i = 1; i <= N; i++) {
				t1 *= i;
				t1 %= p;
			}
			for (long i = 1; i <= R; i++) {
				t2 *= i;
				t2 %= p;
			}
			for (long i = 1; i <= N - R; i++) {
				t2 *= i;
				t2 %= p;
			}
			long t3 = mul(t2, p - 2, p);
			t3 %= p;
			ans = t1 * t3;
			ans %= p;

			builder.append("#" + test_case + " " + ans + "\n");
		}

		System.out.println(builder.toString());
	}

}
