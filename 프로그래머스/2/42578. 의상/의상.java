import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        Map<String, Integer> clothMap = new HashMap<>();
        for (var i : clothes) {
            String type = i[1];
            clothMap.put(type, clothMap.getOrDefault(type, 0) + 1);
        }
        
        int answer = 1;
        for (var i : clothMap.values()) {
            answer *= (i + 1);
        }
        return answer - 1;
    }
}