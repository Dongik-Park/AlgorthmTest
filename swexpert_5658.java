import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class swexpert_5658 {

	static final int MAX_N = 28;
	static final int SHAPE = 4;
	static int N, K;
	static String str;

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			N = sc.nextInt();
			K = sc.nextInt();
			str = sc.next();

			System.out.println("#" + test_case + " " + solve());
		}
	}

	private static int solve() {

		HashMap<String, Integer> caseMap = new HashMap<>();
		// add cases to map
		for (int i = 0; i < N / SHAPE; ++i)
			// right shift
			for (int j = i; j < N; j += N / SHAPE) {
				// make case
				String cur_case = "";
				int cnt = 0;
				while (cnt++ < N / SHAPE)
					cur_case += str.charAt((j + cnt) % N) + "";

				// change case Hex to 10 and add to map
				Integer num = Integer.parseInt(getHexToDec(cur_case));
				caseMap.put(cur_case, num);
			}
		// sort map
		List<String> sortList = sortByValue(caseMap);
		return caseMap.get(sortList.get(K - 1));
	}

	/**
	 * Get string hex data to decimal data
	 * 
	 * @param hex Hex string
	 * @return decimal string
	 */
	private static String getHexToDec(String hex) {
		long v = Long.parseLong(hex, 16);
		return String.valueOf(v);
	}

	/**
	 * Get sorted list of map
	 * 
	 * @param map source map
	 * @return sorted list of map
	 */
	private static List<String> sortByValue(final Map<String, Integer> map) {
		List<String> list = new ArrayList<>();
		list.addAll(map.keySet());
		Collections.sort(list, new Comparator() {
			public int compare(Object o1, Object o2) {
				Object v1 = map.get(o1);
				Object v2 = map.get(o2);
				return ((Comparable) v2).compareTo(v1);
			}
		});
		return list;
	}
}
