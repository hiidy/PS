import java.util.*;

class Solution {
    public String solution(String my_string, int m, int c) {
        StringBuilder string = new StringBuilder();
        
        for (int i = c - 1; i < my_string.length(); i = i + m) {
            string.append(my_string.charAt(i));
        }
        return string.toString();
    }
}