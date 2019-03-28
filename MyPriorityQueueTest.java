package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
/**
 * Sample input below
50
680337
807325
438916
210565
586589
725221
770264
920021
493513
784608
547870
27781
128913
51171
478628
661682
264777
640553
375720
710025
247353
297426
822748
686818
303077
643562
711832
699195
147867
872635
334047
387035
518084
705634
994504
69076
988556
363144
574615
100299
846373
159381
70480
622142
848721
77748
899071
470099
408869
348833

 */
public class MyPriorityQueueTest {
	static final int MAX_SIZE = 10000000;
	static Type[] idxs = new Type[MAX_SIZE]; // Sample array
    static int randomVal[] = new int[MAX_SIZE];
	static PriorityQueue2 pq = new PriorityQueue2(); // Custom priority queue
	
	public static Type[] finxMaxFive(int N, int target) {
		Type[] ret = new Type[5];
		pq.heapInit();
		
		for(int i = 0; i < N; ++i) {
			if(idxs[i].distance <= target)
				pq.heapPush(idxs[i]);
		}
		
		for(int i = 0; i < ret.length; ++i) {
			ret[i] = pq.heapPop();
		}
		
		return ret;
	}
	
	public static void main(String arg[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
         
        int T = Integer.parseInt(br.readLine());
        
        // make random distance
        for (int i = 0; i < randomVal.length; i++)
        {
        	randomVal[i] = (int)(Math.random() * MAX_SIZE) + 1;
        }
        
        // start test case
        long finalStart = System.currentTimeMillis(); // start time
        for (int test_case = 1; test_case <= T; test_case++)
        {
            int N = Integer.parseInt(br.readLine());
            
            
            // data input
            long start = System.currentTimeMillis();
            for (int i = 0; i < N; i++)
            {
                idxs[i] = new Type(i,randomVal[i]);
            }
            long solveTime = System.currentTimeMillis();
            
            // solve
            int data = (int)(Math.random() * (N / 2)) + 1;
            bw.write("#" + test_case + " " + data +"의 검색 결과 : ");
            // 거리가 짧은 상위 5개 추출
            Type[] res = finxMaxFive(N, data);
             for (int i = 0; i < res.length && res[i] != null; i++)
            {
                bw.write(res[i].toString());
            }
            bw.write(" => ");
            
            // data output
            long end = System.currentTimeMillis();
            bw.write((solveTime - start) + "ms / " + (end - solveTime) + "ms / " + (end - start) + "ms 소요(input/solve/total)\n");
        } // end of test case
        long finalEnd = System.currentTimeMillis(); // end time
        bw.write("실행이 완료되었습니다. " + (finalEnd - finalStart) + "ms"); 
        bw.flush();
        
        bw.close();
        br.close();
    } // end of main
} // end of MyPriorityQueueTest

class Type{
	int id;
	int distance;
	public Type(int index, int distance) {
		this.id = index;
		this.distance = distance;
	}
	@Override
	public String toString() {
		return "[" + id + ", " + distance + "]";
	}
} // end of Type

class PriorityQueue2{
	final int MAX_SIZE = MyPriorityQueueTest.MAX_SIZE;
	Type heap[] = new Type[MAX_SIZE]; 
    int heapSize = 0;
 
    void heapInit()
    {
        heapSize = 0;
    }
 
    void heapPush(Type value)
    {
        if (heapSize + 1 > MAX_SIZE)
        {
            return;
        }
 
        heap[heapSize] = value;
 
        int current = heapSize;
        while (current > 0 && heap[current].distance < heap[(current - 1) / 2].distance) 
        {
        	Type temp = heap[(current - 1) / 2];
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
 
    Type heapPop()
    {
        if (heapSize <= 0)
        {
            return null;
        }
 
        Type value = heap[0];
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
                child = heap[current * 2 + 1].distance < heap[current * 2 + 2].distance ? current * 2 + 1 : current * 2 + 2;
            }
 
            if (heap[current].distance < heap[child].distance)
            {
                break;
            }
 
            Type temp = heap[current];
            heap[current] = heap[child];
            heap[child] = temp;
 
            current = child;
        }
        return value;
    }
} // end of PriorityQueue2
