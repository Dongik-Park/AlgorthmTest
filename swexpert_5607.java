import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/**
 * ���Ϸ��� �� 1234567891�� �Ҽ��̱� ������ �丣���� �������� �̿��ؼ� ���� �� �ִ�.
 * a�� m�� ���μ��� ��, a^(m-1)�� m���� ���� �������� 1�̴�.
 * ���� ����(=1234567891�� ���� ������)�� �Ǳ� ���� ������ a^(m-2)�̴�.	
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

			int p = 1234567891; // �������� �ϴ� �� = a

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
