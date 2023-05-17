import java.util.*;

class Solution {
public static int solution(int a, int b, int c, int d) {
        int[] dice = {a, b, c, d};
        Arrays.sort(dice);

        // 1. 네 주사위의 숫자가 모두 같은 경우
        if (dice[0] == dice[3]) {
            return dice[0] * 1111;
        }

        // 2. 세 주사위의 숫자가 같고 나머지 다른 주사위의 숫자가 다른 경우
        if ((dice[0] == dice[2] && dice[3] != dice[0]) || (dice[1] == dice[3] && dice[0] != dice[1])) {
            int p = 0;
            int q = 0;

            if (dice[0] == dice[2]) {
                p = dice[0];
                q = dice[3];
            } else {
                p = dice[1];
                q = dice[0];
            }

            return (10 * p + q) * (10 * p + q);
        }

        // 3. 주사위의 숫자가 두 개씩 같은 경우
        if (dice[0] == dice[1] && dice[2] == dice[3] && dice[0] != dice[2]) {
            int p = dice[0];
            int q = dice[2];

            return (p + q) * Math.abs(p - q);
        }

        // 4. 어느 두 주사위의 숫자가 같고 나머지 두 주사위의 숫자가 각각 다른 경우
        if ((dice[0] == dice[1] && dice[2] != dice[0] && dice[3] != dice[0]) ||
                (dice[1] == dice[2] && dice[0] != dice[1] && dice[3] != dice[1]) ||
                (dice[2] == dice[3] && dice[0] != dice[2] && dice[1] != dice[2])) {
            int p = 0;
            int q = 0;
            int r = 0;

            if (dice[0] == dice[1]) {
                p = dice[0];
                q = dice[2];
                r = dice[3];
            } else if (dice[1] == dice[2]) {
                p = dice[1];
                q = dice[0];
                r = dice[3];
            } else if (dice[2] == dice[3]) {
                p = dice[2];
                q = dice[0];
                r = dice[1];
            }

            return q * r;
        }

        // 5. 네 주사위의 숫자가 모두 다른 경우
        return dice[0];
    }
}