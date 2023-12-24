package leetcode;

import java.util.Scanner;

class minChange {
    public static int minOperations(String s) {
        int startWithOne = 0;  // 10101010...
        int startWithZero = 0; // 01010101...
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                if (s.charAt(i) == '1') startWithZero++;
                else startWithOne++;
            } else {
                if (s.charAt(i) == '0') startWithZero++;
                else startWithOne++;
            }
        }
        return Math.min(startWithOne, startWithZero);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        System.out.println(minOperations(s));
        in.close();
    }
}
