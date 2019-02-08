import java.util.Scanner;

public class Mabangzin {
	private static void printMabangzin2(int N, int map[][]) {
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j)
				System.out.printf("%3d", map[i][j]);
			System.out.println();
		}
		System.out.println();
	}
	
	private static void printMabangzin(int N, int map[][]) { // 결과를 역순으로 출력한다.
		for(int i = N - 1; i >= 0; --i) {
			for(int j = N - 1; j >= 0; --j)
				System.out.printf("%3d", map[i][j]);
			System.out.println();
		}
		System.out.println();
	}
	
	private static void oddMabangzin(int N, int map[][]) {
		int row = 0;
		int col = N / 2; // 시작 지점 초기화

		for (int i = 1; i <= N * N; ++i) {
			map[row][col] = i;
			if (i % N == 0) { // N으로 나누어 떨어지는 순간에 현재바로 아래에 값을 삽입한다.
				++row; 
				if(row == N) row = 0;
			}
			else { // N으로 나누어 떨어지지 않는 경우 row와 col을 1씩 감소시킨다. 
				--row;
				--col;
				if (row < 0) 
					row = N - 1;
				if (col < 0)
					col = N - 1;
			}
		}
		
		printMabangzin(N, map); // 결과를 역순으로 출력한다.
	}
	
	private static void evenMabangzin(int N, int map[][]) {
		boolean check[] = new boolean[N * N + 1];
		int cnt = 1;
		
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j) {
				if(i == j || i + j + 1 == N) {
					map[i][j] = cnt;
					check[cnt] = true;
				}
				++cnt;
			}
		}
		
		int idx = N * N;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j){
				if(map[i][j] == 0) {
					while(check[idx]) {
						--idx;
					}
					check[idx] = true;
					map[i][j] = idx;
				}
			}
		
		printMabangzin2(N, map); // 결과를 정순으로 출력한다.
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int map[][] = new int[N][N];
		if((N & 1) == 1) oddMabangzin(N, map);
		else evenMabangzin(N, map);
	}

}
