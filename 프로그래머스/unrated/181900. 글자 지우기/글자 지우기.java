import java.util.*;

class Solution {
    public String[] solution(String my_string, int[] indices) {
        String[] stringArray = my_string.split(" ");
        List<String> stringList = Arrays.asList(stringArray);
        for (int i = 0; i < indices.length; i++) {
            stringList.remove(i);
            break;
        }
        
        return stringArray;
    }
}