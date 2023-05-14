class Solution {
    public String solution(String my_string, int[][] queries) {
        char[] string = my_string.toCharArray();
        
        for (int i = 0; i < queries.length; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            while (start < end) {
                char tmp = string[start];
                string[start] = string[end];
                string[end] = tmp;
                start ++;
                end --;
                
            }
        }
        
        
        return new String(string);
    }
}