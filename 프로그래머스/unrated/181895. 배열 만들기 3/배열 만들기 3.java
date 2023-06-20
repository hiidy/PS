import java.util.*;

class Solution {
    public List<Integer> solution(int[] arr, int[][] intervals) {
        List<Integer> arrList = new ArrayList<>();
        int a1 = intervals[0][0];
        int b1 = intervals[0][1];
        int a2 = intervals[1][0];
        int b2 = intervals[1][1];
        

        for (int i = a1; i <= b1; i++) {
            arrList.add(arr[i]);
        }
        
        for (int i = a2; i <= b2; i++) {
            arrList.add(arr[i]);
        }
        
        return arrList;
    }
}