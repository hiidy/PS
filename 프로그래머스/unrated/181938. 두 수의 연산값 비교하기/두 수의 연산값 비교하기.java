class Solution {
    public int solution(int a, int b) {
        String concat = String.valueOf(a) + String.valueOf(b);
        int multiply = 2 * a * b;
        return Math.max(Integer.valueOf(concat), multiply);
    }
}