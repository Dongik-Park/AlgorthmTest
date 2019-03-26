package com.ssafy.algo;

import java.util.Scanner;

public class baekjoon_1158 {
	
	static class MyLinkedList {
		MyLinkedList prev;
		MyLinkedList next;
		int val;

		public MyLinkedList(int val) {
			this.val = val;
			this.prev = null;
			this.next = null;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// data input
		int N = sc.nextInt();
		int M = sc.nextInt();
		MyLinkedList head = new MyLinkedList(1);
		MyLinkedList tail = head;
		for (int i = 2; i <= N; ++i) {
			MyLinkedList next = new MyLinkedList(i);
			tail.next = next;
			next.prev = tail;
			tail = next;
		}
		tail.next = head; // make circular
		head.prev = tail;

		// solve
		MyLinkedList target = head;
		int[] res = new int[N]; // output order res array
		int resIdx = 0;
		while (resIdx != N) {
			if (target.next != null) {
				// find next target from current location
				for (int i = 0; i < M - 1; ++i) {
					target = target.next;
				}
				// add current output to res array
				res[resIdx++] = target.val;
				// remove current element and update next target
				MyLinkedList nextTarget = target.next;
				target.next.prev = target.prev;
				target.prev.next = target.next;
				target.next = null;
				target.prev = null;
				target.val = -1;
				target = nextTarget;
			}
		}

		// data output
		System.out.print("<");
		for (int i = 0; i < resIdx - 1; ++i) {
			System.out.print(res[i] + ", ");
		}
		System.out.println(res[resIdx - 1] + ">");
	} // end of main

} // end of class
