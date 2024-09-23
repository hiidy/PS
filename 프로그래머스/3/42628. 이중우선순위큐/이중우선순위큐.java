import java.util.*;


class Solution {
    static void print(Object o) {
        System.out.println(o);
    }
    
    public int[] solution(String[] operations) {
        TreeSet<Integer> set = new TreeSet<>();
        for (String s : operations) {
            String[] ops = s.split(" ");
            if (s.startsWith("I")) {
                set.add(Integer.parseInt(ops[1]));
            } else {
                if (ops[1].startsWith("-")) {
                    set.pollFirst();
                } else {
                    set.pollLast();
                }
            }
        }
        if (set.size() == 0) {
            return new int[]{0, 0};
        }

        int[] answer = {set.last(), set.first()};
        return answer;
    }
}