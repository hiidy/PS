class Solution {
    public int solution(int a, int b) {
        String sum1 = String.valueOf(a) + String.valueOf(b);
        String sum2 = String.valueOf(b) + String.valueOf(a);
        a = Integer.parseInt(sum1);
        b = Integer.parseInt(sum2);
        
        if (a >= b) {
            return a;
        } else if(a < b) {
            return b;
        } 
        int answer = 0;
        return answer;
    }
}