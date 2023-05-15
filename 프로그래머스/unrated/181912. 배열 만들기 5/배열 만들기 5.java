import java.util.*;

class Solution {
    public List<Integer> solution(String[] intStrs, int k, int s, int l) {
        List<Integer> answer = new ArrayList<>();
        
        for (String str : intStrs) {
            String substring = str.substring(s, s+l);
            int num = Integer.parseInt(substring);   
            if (num > k) {
                answer.add(num);
            }
            
        }
        return answer;
    }
}