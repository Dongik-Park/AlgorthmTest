package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;

public class swexpert_4408 {
	static class Room{
		int src;
		int dst;
		public Room(int src, int dst) {
			this.src = src;
			this.dst = dst;
		}
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; ++tc) {
			int []corridor = new int[201];
			int N = Integer.parseInt(br.readLine());
			
			// �����͸� ������ ť ����
			Queue<Room> pq = new ArrayDeque<>();
			for(int i = 0; i < N; ++i) {
				String s[] = br.readLine().split(" ");
				int src = Integer.parseInt(s[0]);
				int dst = Integer.parseInt(s[1]);
				pq.add(new Room(src, dst));
			}
			// �����͸� ���� �� ���ҵ��� �����ϴ� corridor�� ������ ǥ��
			while(!pq.isEmpty()) {
				Room cur = pq.poll();
				int src = (cur.src & 1) == 1 ? cur.src / 2 : cur.src / 2 - 1; // Ȧ���� ��� / 2
				int dst = (cur.dst & 1) == 1 ? cur.dst / 2 : cur.dst / 2 - 1; // ¦���� ��� / 2 - 1
				for(int i = Math.min(src, dst); i <= Math.max(src, dst); ++i) {
					++corridor[i];
				}
			}
			// data output
			int result = 0;
			for(int i = 0; i < corridor.length; ++i) {
				result = result < corridor[i] ? corridor[i] : result;
			}
			bw.write("#" + tc + " " + result + "\n");
		}
		bw.flush();
		
		br.close();
		bw.close();
	}
}
