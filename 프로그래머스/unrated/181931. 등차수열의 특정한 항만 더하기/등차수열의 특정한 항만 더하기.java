class Solution {
    public int solution(int a, int d, boolean[] included) {
        
        int answer = 0;
        int[] seq = new int[included.length];
        for (int i = 0; i < included.length; i++) {
            seq[i] = a + d*i;
            if (included[i] == true) {
                answer += seq[i];
            }
        }
        return answer;
    }
}