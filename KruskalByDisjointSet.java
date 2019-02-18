package com.ssafy.exercise;

import java.util.Arrays;
import java.util.Scanner;
/**
 * 정점 정보를 저장할 클래스
 *
 */
class Edge implements Comparable<Edge>{
	int src; // 정점1
	int dst; // 정점2
	int weight; // 가중치
	public Edge() {
		super();
	}
	public Edge(int src, int dst, int weight) {
		super();
		this.src = src;
		this.dst = dst;
		this.weight = weight;
	}
	@Override
	public int compareTo(Edge o) {
		return this.weight - o.weight;
	}
}
/**
 * MST 알고리즘 중 KRUSKAL 이 더 직관적이고 가단하다.
 * 상호 배타 집합(DisjointSet)을 이용.
 * @author student
 *
 */
public class KruskalByDisjointSet {
	public static final int MAX_INT = Integer.MAX_VALUE;
	
	public static int[]p; // 부모를 저장할 배열
	public static int[]rank ; // 랭크를 저장할 배열
	/**
	 * 멤버 x를 포함하는 새로운 집합을 생성
	 * @param x 포함할 멤버 x
	 */
	public static void makeSet(int x) {
		p[x] = x; // 부모 : 자신의 index로 표시 or -1로 표시
		rank[x] = 0; // 초기값 0 세팅(자바는 생략 가능)
	}
	/**
	 * 멤버 x를 포함하는 집합의 대표자를 리턴
	 * @param x 포함할 멤버 x
	 * @return x 집합의 대표자
	 */
	public static int findSet(int x) {
		if(x == p[x]) { // 자기 자신이 부모일 경우
			return x;
		}
		else {
			p[x] = findSet(p[x]);
			// rank[x] = 1; // 할 필요가 없다. 대표자의 길이(랭크)만 알면 된다.
			return p[x];
		}
	}
	/**
	 * 멤버 x,y의 대표자를 구해서 두 집합을 통합
	 * @param x 포함할 멤버 x
	 * @param y 포함할 멤버 y
	 */
	public static void union(int x, int y) {
		int px = findSet(x); // 대표자 추출
		int py = findSet(y);
		if(px != py) { // 서로 다른 집합일 경우에만 합침
			//p[py] = px; // 두 집합의 대표자를 합친다.
			link(px, py);
		}
	}
	/**
	 * x의 대표자의 집합과 y의 대표자의 집합을 합침
	 * @param px 포함할 멤버 x의 대표자 집합
	 * @param py 포함할 멤버 y의 대표자 집합
	 */
	public static void link(int px, int py) {
		if(rank[px] > rank[py]) {
			p[py] = px; // 작은 쪽을 큰 쪽에 붙인다.
		}
		else {
			p[px] = py;
			if(rank[px] == rank[py]) { // 같은 경우는 rank 값이 증가한다.
				rank[py]++; // 집합의 대표자 랭크가 증가됨.				
			}
		}
	}
	/**
	 * Kruskal example
	 * ex) 
	 * 6 11 // 정점의 개수, 간선의 개수
	 * 0 1 18 // 정점1, 정점2, weight
	 * 0 2 34
	 *  :
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int v = sc.nextInt(); // 정점의 개수
		int e = sc.nextInt(); // 간선의 개수
		
		p = new int[v + 1]; 
		rank = new int[p.length];
		
		Edge[] edges = new Edge[e]; // 간선의 개수만큼 생성
		for(int i = 0; i < e; ++i) { // 간선 정보 입력
			edges[i] = new Edge(sc.nextInt(), sc.nextInt(), sc.nextInt());
		}	
		
		Edge result[] = new Edge[v]; // MST 저장 배열
		e = 0; // 결과에 사용되는 변수
		int i = 0; // edge에 저장되는 index 변수
		for (i = 0; i < v; ++i) {
			result[i] = new Edge();
		}
		// 1단계 : 모든 가장자리를 비결합적인 순서로 정렬
		// 주어진 그래프를 변경할 수 없는 경우, edge 복사본 생성
		Arrays.sort(edges);
		// 단일 요소로 V 하위집합 생성
		for (i = 0; i < v; ++i) {
			makeSet(i);
		}
		i = 0; // 다음 edge를 선택하는데 사용되는 index 변수
		int sum = 0;
		// edge의 수는 V-1 ( edge 수 == V - 1일 경우 최소 신장트리 완성 )
		while (e < v - 1) {
			// 2단계 : 가장 작은 edge를 선택
			// 다음 반복에 대한 i변수 증가
			Edge next_edge = edges[i++];
			int x = findSet(next_edge.src); // 현재의 부모 노드
			int y = findSet(next_edge.dst); // 현재의 자식 노드
			// edge가 사이클이 안되는 경우, 결과에 포함된 결과를 포함하고 다음 edge에 대한 결과를 증가시킨다.
			if (x != y) {
				result[e++] = next_edge;
				
				System.out.println(next_edge.src + " - " + next_edge.dst + " " + next_edge.weight);
				sum += next_edge.weight;
						
				union(x, y);
			}
		}
		/*for (i = 0; i < e; ++i) {
			System.out.println(result[i].src + " -- " + result[i].dst + " == " + result[i].weight);
		}*/
		
		System.out.println("Sum of kruskal = " + sum);
	}
}
