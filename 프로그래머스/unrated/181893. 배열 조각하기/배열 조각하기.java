import java.util.*;

class Solution {
    public int[] solution(int[] arr, int[] query) {
        int[] answer = {};
        
        for (int i = 0; i < query.length; i++) {
            int index = query[i];
            if (i % 2 == 0) {
                arr = Arrays.copyOfRange(arr, 0, index+1);
            } else {
                arr = Arrays.copyOfRange(arr, index, arr.length);
            }
        }
        return arr;
    }
}