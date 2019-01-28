
public class DecToHex {
	public static void main(String[] args) {
		System.out.println("10 -> " + decToHex(10));
		System.out.println("11 -> " + decToHex(11));
		System.out.println("12 -> " + decToHex(12));
		System.out.println("13 -> " + decToHex(13));
		System.out.println("14 -> " + decToHex(14));
		System.out.println("15 -> " + decToHex(15));
		System.out.println("16 -> " + decToHex(16));
		System.out.println("258 -> " + decToHex(258));
		System.out.println("19 -> " + decToHex(19));
		System.out.println("278 -> " + decToHex(278));
		System.out.println("1099 -> " + decToHex(1099));
		System.out.println("2154 -> " + decToHex(2154));
		/*
		 * 10 -> 0xA 
		 * 11 -> 0xB 
		 * 12 -> 0xC 
		 * 13 -> 0xD 
		 * 14 -> 0xE 
		 * 15 -> 0xF 
		 * 16 -> 0x10 
		 * 258 -> 0x102 
		 * 19 -> 0x13 
		 * 278 -> 0x116 
		 * 1099 -> 0x44B 
		 * 2154 -> 0x86A
		 */
	}

	public static String decToHex(int num) {
		StringBuilder sb = new StringBuilder();

		while (num > 0) { // 0�� �ɶ����� �ݺ�
			int temp = num % 16; // 16���� �������� ���� ������
			if (temp >= 10) // 10�̻��� ��� ���ĺ����� ǥ��
				sb.append((char) (temp - 10 + 'A') + "");
			else // 10 �̸��� ��� ���ڷ� ǥ��
				sb.append(temp);
			num /= 16; // 16���� ���� ���� ����
		}
		// ����� ��¤� ��ȯ
		return "0x" + sb.reverse().toString();
	}
}
