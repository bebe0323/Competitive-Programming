package leetcode;

import java.util.Scanner;

class Easy {

    public static int maxScore(String s) {
        int zero = 0;
        int one = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                one++;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') zero++;
            else one--;
            ans = Math.max(ans, one + zero);
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        System.out.println(maxScore(s));
        in.close();
    }
}

// https://leetcode.com/problems/maximum-score-after-splitting-a-string/