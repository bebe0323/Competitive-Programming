package leetcode;

import java.util.HashMap;
import java.util.Scanner;

class Pathcrossing {
    public static boolean isPathCrossing(String path) {
        int x = 0;
        int y = 0;
        HashMap<Integer, Boolean> visitedNodes = new HashMap<>();
        visitedNodes.put(0, true);
        for (int i = 0; i < path.length(); i++) {
            if (path.charAt(i) == 'N') y++;
            if (path.charAt(i) == 'S') y--;
            if (path.charAt(i) == 'E') x++;
            if (path.charAt(i) == 'W') x--;
            // turns (x,y) coordinate into one singel integer value
            Integer value = x * 100000 + y;
            if (visitedNodes.get(value) != null) return true;
            visitedNodes.put(value, true);
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        System.out.println(isPathCrossing(s));
        in.close();
    }
}
