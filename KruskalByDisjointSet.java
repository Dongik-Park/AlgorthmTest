package com.ssafy.exercise;

import java.util.Arrays;
import java.util.Scanner;
/**
 * ���� ������ ������ Ŭ����
 *
 */
class Edge implements Comparable<Edge>{
	int src; // ����1
	int dst; // ����2
	int weight; // ����ġ
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
 * MST �˰��� �� KRUSKAL �� �� �������̰� �����ϴ�.
 * ��ȣ ��Ÿ ����(DisjointSet)�� �̿�.
 * @author student
 *
 */
public class KruskalByDisjointSet {
	public static final int MAX_INT = Integer.MAX_VALUE;
	
	public static int[]p; // �θ� ������ �迭
	public static int[]rank ; // ��ũ�� ������ �迭
	/**
	 * ��� x�� �����ϴ� ���ο� ������ ����
	 * @param x ������ ��� x
	 */
	public static void makeSet(int x) {
		p[x] = x; // �θ� : �ڽ��� index�� ǥ�� or -1�� ǥ��
		rank[x] = 0; // �ʱⰪ 0 ����(�ڹٴ� ���� ����)
	}
	/**
	 * ��� x�� �����ϴ� ������ ��ǥ�ڸ� ����
	 * @param x ������ ��� x
	 * @return x ������ ��ǥ��
	 */
	public static int findSet(int x) {
		if(x == p[x]) { // �ڱ� �ڽ��� �θ��� ���
			return x;
		}
		else {
			p[x] = findSet(p[x]);
			// rank[x] = 1; // �� �ʿ䰡 ����. ��ǥ���� ����(��ũ)�� �˸� �ȴ�.
			return p[x];
		}
	}
	/**
	 * ��� x,y�� ��ǥ�ڸ� ���ؼ� �� ������ ����
	 * @param x ������ ��� x
	 * @param y ������ ��� y
	 */
	public static void union(int x, int y) {
		int px = findSet(x); // ��ǥ�� ����
		int py = findSet(y);
		if(px != py) { // ���� �ٸ� ������ ��쿡�� ��ħ
			//p[py] = px; // �� ������ ��ǥ�ڸ� ��ģ��.
			link(px, py);
		}
	}
	/**
	 * x�� ��ǥ���� ���հ� y�� ��ǥ���� ������ ��ħ
	 * @param px ������ ��� x�� ��ǥ�� ����
	 * @param py ������ ��� y�� ��ǥ�� ����
	 */
	public static void link(int px, int py) {
		if(rank[px] > rank[py]) {
			p[py] = px; // ���� ���� ū �ʿ� ���δ�.
		}
		else {
			p[px] = py;
			if(rank[px] == rank[py]) { // ���� ���� rank ���� �����Ѵ�.
				rank[py]++; // ������ ��ǥ�� ��ũ�� ������.				
			}
		}
	}
	/**
	 * Kruskal example
	 * ex) 
	 * 6 11 // ������ ����, ������ ����
	 * 0 1 18 // ����1, ����2, weight
	 * 0 2 34
	 *  :
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int v = sc.nextInt(); // ������ ����
		int e = sc.nextInt(); // ������ ����
		
		p = new int[v + 1]; 
		rank = new int[p.length];
		
		Edge[] edges = new Edge[e]; // ������ ������ŭ ����
		for(int i = 0; i < e; ++i) { // ���� ���� �Է�
			edges[i] = new Edge(sc.nextInt(), sc.nextInt(), sc.nextInt());
		}	
		
		Edge result[] = new Edge[v]; // MST ���� �迭
		e = 0; // ����� ���Ǵ� ����
		int i = 0; // edge�� ����Ǵ� index ����
		for (i = 0; i < v; ++i) {
			result[i] = new Edge();
		}
		// 1�ܰ� : ��� �����ڸ��� ��������� ������ ����
		// �־��� �׷����� ������ �� ���� ���, edge ���纻 ����
		Arrays.sort(edges);
		// ���� ��ҷ� V �������� ����
		for (i = 0; i < v; ++i) {
			makeSet(i);
		}
		i = 0; // ���� edge�� �����ϴµ� ���Ǵ� index ����
		int sum = 0;
		// edge�� ���� V-1 ( edge �� == V - 1�� ��� �ּ� ����Ʈ�� �ϼ� )
		while (e < v - 1) {
			// 2�ܰ� : ���� ���� edge�� ����
			// ���� �ݺ��� ���� i���� ����
			Edge next_edge = edges[i++];
			int x = findSet(next_edge.src); // ������ �θ� ���
			int y = findSet(next_edge.dst); // ������ �ڽ� ���
			// edge�� ����Ŭ�� �ȵǴ� ���, ����� ���Ե� ����� �����ϰ� ���� edge�� ���� ����� ������Ų��.
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
