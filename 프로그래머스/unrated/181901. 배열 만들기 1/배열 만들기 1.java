import java.util.*;

class Solution {
    public List<Integer> solution(int n, int k) {
        List<Integer> answer = new ArrayList<>();
        
        for (int i = 1; i <= n; i++) {
            if (i % k == 0) {
                answer.add(i);
                
            } 
        }
        return answer;
    }
}