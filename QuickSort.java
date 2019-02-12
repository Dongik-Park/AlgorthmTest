package com.ssafy.exercise;

import java.util.Arrays;

public class QuickSort {
	
	public static void swap(int arr[], int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	private static int partition(int A[], int p, int r) {
		int x = A[r];
		int i = p - 1;
		
		for(int j = p; j < r; ++j) {
			if(A[j] <= x) {
				++i;
				swap(A, i, j);
			}
		}
		// i ~ j 에는 현재 가장 우측(=pivot)보다 큰 수들이 저장되어있다.
		// 해서 r과 i + 1의 위치를 바꾸어주면 pivot 우측으로는 큰 수들이 저장된다.
		swap(A, i + 1, r);
		return i + 1;
	}
	
	public static void quickSort(int A[], int l, int r) {
		if(l < r) {
			int s = partition(A, l, r);
			quickSort(A, l, s - 1);
			quickSort(A, s + 1, r);
		}
	}
	
	public static void main(String[] args) {
		int []arr = {11, 45, 23, 81, 28, 34};
		int []arr2 = {11, 45, 22, 81, 23, 34, 99, 22, 17, 8};
		int []arr3 = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
		
		System.out.println("before : " + Arrays.toString(arr));
		quickSort(arr, 0, arr.length - 1);
		System.out.println("after : " + Arrays.toString(arr));
		
		System.out.println("before : " + Arrays.toString(arr2));
		quickSort(arr2, 0, arr2.length - 1);
		System.out.println("after : " + Arrays.toString(arr2));
		
		System.out.println("before : " + Arrays.toString(arr3));
		quickSort(arr3, 0, arr3.length - 1 );
		System.out.println("after : " + Arrays.toString(arr3));
	}

}
