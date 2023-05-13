import java.util.*;

class Solution {
    public List<Integer> solution(int l, int r) {
        List<Integer> answer = new ArrayList<>();
        
        for (int i = l; i <= r; i++) {
            if (contains05(i)) {
                answer.add(i);
            }
        }
        
        if (answer.isEmpty()) {
            answer.add(-1);
            return answer;
        }
        
        return answer;
    }
    
    private boolean contains05(int n) {
        String str = String.valueOf(n);
        
        for (char c : str.toCharArray()) {
            if (c != '0' && c != '5') {
                return false;
            }
        }
        return true;
    }
}