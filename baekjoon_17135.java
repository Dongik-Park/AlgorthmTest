import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;

public class baekjoon_17135 {
	
	private static int N, M, D, res;
	private static int [][]map = new int[17][17];
	private static LinkedList<Point> targets = new LinkedList<>();
	private static LinkedList<Point> shooters = new LinkedList<>();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		// data input
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		for(int i = 0; i < N; ++i){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < M; ++j){
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 1){
					targets.add(new Point(i, j));
				}
			}
		}
		
		// solve
		res = 0;
		solve(0);
		System.out.println(res);
	}
	
	private static void solve(int idx){
		// 1. ������ �Ϸ�Ǹ� �ùķ��̼� ����
		if(shooters.size() == 3){
			// Ÿ�� ����
			LinkedList<Point> tempTarget = new LinkedList<>();
			for(int i = 0; i < targets.size(); ++i)
				tempTarget.add(new Point(targets.get(i).x, targets.get(i).y));
			
			int cnt = 0;
			while(!tempTarget.isEmpty()){
				// ������ Ÿ�� ����
				Set<Target> curTarget = new HashSet<>();
				// 1. �� ��ġ���� ���� ��ġ���� ���� ������ ���� ���ʿ� �ִ� �ָ� ã�´�.
				for(int i = 0; i < 3; ++i){
					// ���� �ü�
					Point cur = shooters.get(i); 
					// 1. search target
					PriorityQueue<Target> pq = new PriorityQueue<>();
					for(int j = 0; j < tempTarget.size(); ++j){
						int curD = Math.abs(cur.x - tempTarget.get(j).x) + Math.abs(cur.y - tempTarget.get(j).y);
						if(curD <= D){
							pq.add(new Target(tempTarget.get(j).x, tempTarget.get(j).y, curD));
						}
					}
					// 2. add best target
					if(!pq.isEmpty())
						curTarget.add(pq.poll());
				}
				// 2. ������ �ֵ��� targets���� �����Ѵ�.
				for(Target cur : curTarget){
					for(int i = 0; i < tempTarget.size(); ++i){ // ��ġ�ϴ� Ÿ���� ã�� ����
						if(cur.x == tempTarget.get(i).x && cur.y == tempTarget.get(i).y){
							tempTarget.remove(i);
							++cnt;
							break;
						}
					}
				}
				ArrayList<Point> temp1 = new ArrayList<>();
				// 3. ���� �ֵ��� ��ġ�� ��ĭ �̵��Ѵ�.
				for(int i = 0; i < tempTarget.size(); ++i){
					tempTarget.get(i).x = tempTarget.get(i).x + 1; // ��ĭ �Ʒ��� �̵�
					if(tempTarget.get(i).x < N){ 
						temp1.add(tempTarget.get(i));						
					}
				}
				tempTarget = new LinkedList<>();
				for(int i = 0; i < temp1.size(); ++i)
					tempTarget.add(temp1.get(i));
			}
			res = res < cnt ? cnt : res;
			
			return;
		}
		if(idx == M){
			return;
		}
		// 1. dfs�� �� ������ ��ġ�� �����Ѵ�.
		shooters.add(new Point(N, idx));
		solve(idx + 1);
		// 2. ���� ��ġ ������
		shooters.removeLast();
		solve(idx + 1);
		
	}
	
	static class Target implements Comparable<Target>{
		int x;
		int y;
		int d;
		public Target(int x, int y, int d) {
			this.x = x;
			this.y = y;
			this.d = d;
		}
		@Override
		public int compareTo(Target o) {
			if(this.d == o.d){ // �Ÿ��� ���� ��� y��ǥ�� ���� ģ����
				return this.y - o.y;
			}
			else{
				return this.d - o.d;
			}
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + d;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Target other = (Target) obj;
			if (d != other.d)
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
		
	}
	
	static class Point {
		int x;
		int y;
		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Point other = (Point) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}
		
	}

}
