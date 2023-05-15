import java.util.*;

class Solution {
    public String[] solution(String my_string) {
        String[] answer = new String[my_string.length()];
        int start = 0;
        int end = my_string.length() - 1;
        
        for (int i = start; i <= end; i++) {
            answer[i] = my_string.substring(i, end+1);
        }
        Arrays.sort(answer);
        
        return answer;
    }
}