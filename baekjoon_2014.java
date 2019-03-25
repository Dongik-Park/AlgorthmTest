package com.ssafy.algo;

import java.util.Scanner;

public class baekjoon_2014 {
	
	static final int MAX_K = 541;
	static boolean [] chk = new boolean[MAX_K * MAX_K];
	private static int K;
	private static int N;
	private static long[] prime;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// data input
	    K = sc.nextInt();
	    N = sc.nextInt();
	    prime = new long[K];
	    MyPriorityQueue q = new MyPriorityQueue();
	    for (int i = 0; i < K; i++) {
	        prime[i] = sc.nextInt();
	        q.heapPush(prime[i]);
	    }
	    
	    // solve
	    // 소수 리스트, 소수와 비교하여 곱한 값 넣는 큐, 최종 리스트
	    // 큐의 맨 앞 요소를 빼서 각 소수를 곱하면서 큐에 다시 넣는다. => 현재 최소값을 기준으로 소수 목록을 곱하여 pq에 삽입
	    //mygumi.tistory.com/183 [마이구미의 HelloWorld]
	    long head = 0;
	    for (int i = 0; i < N; i++) {
	        // n번째 뺀 값이 n번째 수가 된다.
	        head = q.heapPop();
	 
	        // 큐를 활용하여 삽입마다 오름차순으로 정렬됨으로써 원하는 값들을 리스트에 저장 가능.
	        for (int j = 0; j < K; j++) {
	            long value = head * prime[j];
	            q.heapPush(value);
	 
	            if (head % prime[j] == 0) {
	                break;
	            }
	        }
	       /* for(int j = 0; j < q.heapSize; ++j)
	        	System.out.print(q.heap[j] + " ");
	        System.out.println();*/
	    }
	    
	    // data output
	    System.out.println(head);
	}

}

class MyPriorityQueue{
	
	final int MAX_SIZE = 1000000;
	 
    long heap[] = new long[MAX_SIZE];
    int heapSize = 0;
 
    void heapInit()
    {
        heapSize = 0;
    }
 
    void heapPush(long value)
    {
        if (heapSize + 1 > MAX_SIZE)
        {
            return;
        }
 
        heap[heapSize] = value;
 
        int current = heapSize;
        while (current > 0 && heap[current] < heap[(current - 1) / 2]) 
        {
        	long temp = heap[(current - 1) / 2];
            heap[(current - 1) / 2] = heap[current];
            heap[current] = temp;
            current = (current - 1) / 2;
        }
 
        heapSize = heapSize + 1;
    }
    
    boolean isEmpty() {
    	if(heapSize <= 0)
    		return true;
    	return false;
    }
 
    long heapPop()
    {
        if (heapSize <= 0)
        {
            return -1;
        }
 
        long value = heap[0];
        heapSize = heapSize - 1;
 
        heap[0] = heap[heapSize];
 
        int current = 0;
        while (current < heapSize && current * 2 + 1 < heapSize)
        {
            int child;
            if (current * 2 + 2 >= heapSize)
            {
                child = current * 2 + 1;
            }
            else
            {
                child = heap[current * 2 + 1] < heap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;
            }
 
            if (heap[current] < heap[child])
            {
                break;
            }
 
            long temp = heap[current];
            heap[current] = heap[child];
            heap[child] = temp;
 
            current = child;
        }
        return value;
    }
}