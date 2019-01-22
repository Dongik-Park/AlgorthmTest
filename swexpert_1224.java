package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class swexpert_1224 {
	static String getPostfix(String input) { 
		String result = "";
		Stack<Character> stack = new Stack<>();
		for (int i = 0; i < input.length(); i++) {
			char ch = input.charAt(i);
			if (ch >= '0' && ch <= '9') { 
				result += ch;
			} else if (ch == ')') { 
				char temp;
				while ((temp = stack.pop()) != '(') {
					result += temp;
				}
			} else {
				while (!stack.isEmpty() && ch != '(' 
						&& getPriority(stack.peek()) >= getPriority(ch)) { 
					result += stack.pop();
				}
				stack.push(ch);
			}
		}
		while (!stack.isEmpty()) { 
			result += stack.pop();
		}
		return result;
	}

	static int calPost(String postfix) { // ����ǥ����� ����ϴ� �޼���
		Stack<Integer> stack2 = new Stack<>();
		for (int i = 0; i < postfix.length(); i++) {
			char c = postfix.charAt(i);
			if (c >= '0' && c <= '9') {
				stack2.push(c - '0');
			} else if (c == '+') {
				int a = stack2.pop();
				int b = stack2.pop();
				stack2.push(a + b);
			} else if (c == '*') {
				int cc = stack2.pop();
				int d = stack2.pop();
				stack2.push(cc * d);
			}
		}
		return stack2.pop();
	}

	static int getPriority(char c) { // Ư�� �������� �켱������ ���ڷ� �����ϴ� �޼���
		if (c == '(') {
			return 1;
		} else if (c == '+') {
			return 2;
		} else if (c == '*') {
			return 3;
		} else {
			return 0;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int i = 1; i <= 10; i++) {
			int len = Integer.parseInt(br.readLine().trim());
			String str = br.readLine().trim();
			String postfixStr = getPostfix(str);
			System.out.printf("#%d %d\n", i, calPost(postfixStr));
		}

	}
}
