class Solution {
    public String solution(String my_string, int n) {
        int start = my_string.length() - n;
        int end = my_string.length();
        String substring = my_string.substring(start, end);

        return substring;
    }
}