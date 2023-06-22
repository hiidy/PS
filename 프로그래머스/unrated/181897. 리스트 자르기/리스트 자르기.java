import java.util.*;

class Solution {
    public List<Integer> solution(int n, int[] slicer, int[] num_list) {
        List<Integer> result = new ArrayList<>();
        int a = slicer[0];
        int b = slicer[1];
        int c = slicer[2];

        Integer[] numArr = Arrays.stream(num_list).boxed().toArray(Integer[]::new);

        if (n == 1) {
            result = Arrays.asList(Arrays.copyOfRange(numArr, 0, b + 1));
        } else if (n == 2) {
            result = Arrays.asList(Arrays.copyOfRange(numArr, a, numArr.length));
        } else if (n == 3) {
            result = Arrays.asList(Arrays.copyOfRange(numArr, a, b + 1));
        } else if (n == 4) {
            for (int i = a; i <= b; i += c) {
                result.add(numArr[i]);
            }
        }

        return result;
    }
}

