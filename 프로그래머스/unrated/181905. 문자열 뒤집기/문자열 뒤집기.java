class Solution {
    public String solution(String my_string, int s, int e) {
        char[] string = my_string.toCharArray();
        
        while(s < e) {
            char tmp = string[s];
            string[s++] = string[e];
            string[e--] = tmp;
        }
        
        
        return new String(string);
    }
}