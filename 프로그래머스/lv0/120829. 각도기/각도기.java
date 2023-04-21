class Solution {
    public int solution(int angle) {
        if (angle == 90){
            return 2;
        }
        if (0<angle && angle<90){
            return 1;
        }
        if (angle == 180){
            return 4;
        }
        return 3;
    }
}