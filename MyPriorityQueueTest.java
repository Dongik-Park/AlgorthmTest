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

 * Sample output below
#1 242394의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 15ms / 0ms / 15ms 소요(input/solve/total)
#2 38439의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 268ms / 16ms / 284ms 소요(input/solve/total)
#3 21561의 검색 결과 : [382203, 42][167134, 81][363536, 109][356223, 142][203758, 188] => 0ms / 0ms / 0ms 소요(input/solve/total)
#4 31093의 검색 결과 : [167134, 81][203758, 188][177039, 197][145649, 235][72410, 258] => 0ms / 0ms / 0ms 소요(input/solve/total)
#5 214962의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 0ms / 0ms / 0ms 소요(input/solve/total)
#6 64766의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 0ms / 15ms / 15ms 소요(input/solve/total)
#7 352746의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 94ms / 0ms / 94ms 소요(input/solve/total)
#8 342561의 검색 결과 : [490304, 11][495664, 16][812135, 32][382203, 42][440308, 49] => 16ms / 0ms / 16ms 소요(input/solve/total)
#9 214379의 검색 결과 : [490304, 11][382203, 42][440308, 49][167134, 81][487578, 92] => 0ms / 0ms / 0ms 소요(input/solve/total)
#10 194303의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 0ms / 0ms / 0ms 소요(input/solve/total)
#11 71308의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 15ms / 0ms / 15ms 소요(input/solve/total)
#12 3538의 검색 결과 : [25785, 286][17661, 441][25381, 550][6160, 676][2582, 847] => 0ms / 0ms / 0ms 소요(input/solve/total)
#13 14713의 검색 결과 : [72410, 258][84860, 262][25785, 286][100236, 288][84790, 392] => 0ms / 0ms / 0ms 소요(input/solve/total)
#14 3525의 검색 결과 : [25785, 286][17661, 441][25381, 550][6160, 676][2582, 847] => 0ms / 0ms / 0ms 소요(input/solve/total)
#15 46514의 검색 결과 : [382203, 42][440308, 49][167134, 81][363536, 109][458802, 113] => 0ms / 0ms / 0ms 소요(input/solve/total)
#16 36439의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 125ms / 0ms / 125ms 소요(input/solve/total)
#17 14239의 검색 결과 : [167134, 81][203758, 188][177039, 197][145649, 235][72410, 258] => 0ms / 0ms / 0ms 소요(input/solve/total)
#18 299370의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 16ms / 0ms / 16ms 소요(input/solve/total)
#19 68860의 검색 결과 : [167134, 81][363536, 109][356223, 142][203758, 188][177039, 197] => 0ms / 0ms / 0ms 소요(input/solve/total)
#20 242574의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 0ms / 0ms / 0ms 소요(input/solve/total)
#21 96492의 검색 결과 : [167134, 81][203758, 188][177039, 197][145649, 235][72410, 258] => 16ms / 0ms / 16ms 소요(input/solve/total)
#22 83975의 검색 결과 : [167134, 81][203758, 188][177039, 197][145649, 235][72410, 258] => 0ms / 0ms / 0ms 소요(input/solve/total)
#23 387715의 검색 결과 : [490304, 11][495664, 16][812135, 32][382203, 42][440308, 49] => 0ms / 0ms / 0ms 소요(input/solve/total)
#24 26343의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 15ms / 0ms / 15ms 소요(input/solve/total)
#25 30403의 검색 결과 : [167134, 81][203758, 188][177039, 197][145649, 235][72410, 258] => 0ms / 0ms / 0ms 소요(input/solve/total)
#26 158380의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 110ms / 0ms / 110ms 소요(input/solve/total)
#27 197326의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 0ms / 0ms / 0ms 소요(input/solve/total)
#28 117752의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 0ms / 0ms / 0ms 소요(input/solve/total)
#29 64415의 검색 결과 : [145649, 235][72410, 258][84860, 262][140392, 270][25785, 286] => 0ms / 0ms / 0ms 소요(input/solve/total)
#30 340959의 검색 결과 : [490304, 11][495664, 16][812135, 32][382203, 42][440308, 49] => 0ms / 15ms / 15ms 소요(input/solve/total)
#31 77731의 검색 결과 : [167134, 81][203758, 188][177039, 197][145649, 235][72410, 258] => 0ms / 0ms / 0ms 소요(input/solve/total)
#32 10723의 검색 결과 : [382203, 42][167134, 81][363536, 109][356223, 142][203758, 188] => 0ms / 0ms / 0ms 소요(input/solve/total)
#33 144269의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 0ms / 0ms / 0ms 소요(input/solve/total)
#34 342414의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 0ms / 0ms / 0ms 소요(input/solve/total)
#35 140689의 검색 결과 : [490304, 11][495664, 16][812135, 32][382203, 42][440308, 49] => 0ms / 0ms / 0ms 소요(input/solve/total)
#36 4692의 검색 결과 : [25785, 286][17661, 441][25381, 550][6160, 676][54272, 708] => 16ms / 0ms / 16ms 소요(input/solve/total)
#37 307061의 검색 결과 : [490304, 11][495664, 16][812135, 32][382203, 42][440308, 49] => 96ms / 3ms / 99ms 소요(input/solve/total)
#38 41209의 검색 결과 : [167134, 81][356223, 142][203758, 188][177039, 197][145649, 235] => 1ms / 0ms / 1ms 소요(input/solve/total)
#39 244390의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 2ms / 2ms / 4ms 소요(input/solve/total)
#40 43347의 검색 결과 : [72410, 258][84860, 262][25785, 286][100236, 288][84790, 392] => 0ms / 0ms / 0ms 소요(input/solve/total)
#41 214233의 검색 결과 : [490304, 11][495664, 16][812135, 32][382203, 42][440308, 49] => 3ms / 2ms / 5ms 소요(input/solve/total)
#42 75461의 검색 결과 : [145649, 235][72410, 258][84860, 262][140392, 270][25785, 286] => 0ms / 0ms / 0ms 소요(input/solve/total)
#43 13972의 검색 결과 : [25785, 286][17661, 441][25381, 550][6160, 676][54272, 708] => 1ms / 0ms / 1ms 소요(input/solve/total)
#44 61466의 검색 결과 : [490304, 11][495664, 16][382203, 42][440308, 49][496410, 51] => 2ms / 1ms / 3ms 소요(input/solve/total)
#45 119166의 검색 결과 : [490304, 11][495664, 16][812135, 32][382203, 42][440308, 49] => 2ms / 2ms / 4ms 소요(input/solve/total)
#46 31454의 검색 결과 : [72410, 258][25785, 286][17661, 441][25381, 550][6160, 676] => 0ms / 0ms / 0ms 소요(input/solve/total)
#47 280142의 검색 결과 : [490304, 11][495664, 16][812135, 32][382203, 42][440308, 49] => 3ms / 1ms / 4ms 소요(input/solve/total)
#48 83191의 검색 결과 : [382203, 42][440308, 49][167134, 81][363536, 109][458802, 113] => 0ms / 0ms / 0ms 소요(input/solve/total)
#49 49442의 검색 결과 : [382203, 42][167134, 81][363536, 109][356223, 142][203758, 188] => 93ms / 0ms / 93ms 소요(input/solve/total)
#50 8609의 검색 결과 : [167134, 81][203758, 188][177039, 197][145649, 235][72410, 258] => 0ms / 0ms / 0ms 소요(input/solve/total)
실행이 완료되었습니다. 966ms
 */
public class MyPriorityQueueTest {
	static final int MAX_SIZE = 10000000; // Max value
	static Type[] idxs = new Type[MAX_SIZE]; // Sample array
        static int randomVal[] = new int[MAX_SIZE]; // Random value
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
