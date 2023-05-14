class Solution {
    public String solution(String my_string, int[] index_list) {
        char[] string = my_string.toCharArray();
        String answer = "";
        for (int i : index_list) {
            answer += string[i];
        }
        return answer;
    }
}