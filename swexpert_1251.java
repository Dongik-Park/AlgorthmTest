package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution_1251_�ϳ���_�ڵ��� {
    static int n;
 
    static class Island {
        int x; // x��ǥ
        int y; // y��ǥ
        long len; // �����ͳ� ����
    }
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
 
        for (int tc = 1; tc <= T; tc++) {
        	// data input
            n = Integer.parseInt(br.readLine());
            Island[] islands = new Island[n];
            boolean[] visited = new boolean[n];
 
            StringTokenizer stX = new StringTokenizer(br.readLine());
            StringTokenizer stY = new StringTokenizer(br.readLine());
            
            for (int i = 0; i < n; i++) {
                islands[i] = new Island();
                islands[i].x = Integer.parseInt(stX.nextToken());
                islands[i].y = Integer.parseInt(stY.nextToken());
                islands[i].len = Long.MAX_VALUE;
            }
 
            double e = Double.parseDouble(br.readLine());
            long result = 0;
            result = dijkstra(islands, visited, result);

			// accumulate output
			sb.append("#" + tc + " " + Math.round(result * e) + "\n");
        }
        System.out.println(sb);
    }
 
    static long dijkstra(Island[] islands, boolean[] visited, long result) {
        islands[0].len = 0;
 
        for (int i = 0; i < n; i++) {
            long cost = Long.MAX_VALUE;
            int index = 0; // �ּ� ����ġ�� ����� �迭�� index
            // ���� ���� ����� ã�´�.
            for (int j = 0; j < n; j++) {
                if (!visited[j] && islands[j].len < cost) {
                    cost = islands[j].len;
                    index = j;
                }
            }
            visited[index] = true;
            result += islands[index].len;
            // ������ ������ ���ؼ� �� �� �ִ�(������) ������ ����ġ�� �����ϱ�
            for (int j = 0; j < n; j++) {
                if (!visited[j]) { // �湮���� ���� ���� �� �ּ� ��� ����
                    cost = (long) Math.pow(islands[index].x - islands[j].x, 2)
                            + (long) Math.pow(islands[index].y - islands[j].y, 2);
                    if (cost < islands[j].len) // ��� ����
                        islands[j].len = cost;
                }
            }
        }
 
        return result;
    }
 
}