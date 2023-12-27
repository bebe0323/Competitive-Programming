package leetcode;

import java.util.Scanner;

class minToMakeColorful {
    public static int minCost(String colors, int[] neededTime) {
        int ret = 0;
        int mx = neededTime[0];
        int sum = neededTime[0];
        for (int i = 1; i < colors.length(); i++) {
            if (colors.charAt(i) == colors.charAt(i - 1)) {
                mx = Math.max(mx, neededTime[i]);
                sum += neededTime[i];
            } else {
                // leaving the balloon with maximum removing time
                ret += sum - mx;
                mx = neededTime[i];
                sum = neededTime[i];
            }
        }
        ret += sum - mx;
        return ret;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String colors = in.next();
        // get input of neededTime array
        int n = in.nextInt();
        int[] neededTime = new int[n];
        for (int i = 0; i < n; i++) {
            neededTime[i] = in.nextInt();
        }
        //
        System.out.println(minCost(colors, neededTime));
        in.close();
    }
}
