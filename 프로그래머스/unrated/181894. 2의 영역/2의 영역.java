import java.util.*;

class Solution {
    public List<Integer> solution(int[] arr) {
        List<Integer> answer = new ArrayList<>();
        int start = -1;
        int end = -1;
        
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 2) {
                start = i;
                break;
            }
        }
        
        for (int i = arr.length - 1; i >= 0; i--) {
            if (arr[i] == 2) {
                end = i;
                break;
            }
        }
        
        
        if (start == end && start != -1) {
            answer.add(arr[start]);
        } else if (start == -1) {
            answer.add(-1);
        } else {
            for (int i = start; i <= end; i++) {
                answer.add(arr[i]);
            }
        }
        
        
        return answer;
    }
}