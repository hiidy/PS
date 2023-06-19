// import java.util.*;

// class Solution {
//     public List<String> solution(String my_string, int[] indices) {
//         String[] stringArray = my_string.split(" ");
//         List<String> stringList = new ArrayList<>(Arrays.asList(stringArray));
//         Arrays.sort(indices);
        
//         for (int i = indices.length - 1; i >= 0; i--) {
//             int index = indices[i];
//             stringList.remove(index);
//         }
        
//         return stringList;
//     }
// }

import java.util.*;

class Solution {
    public String solution(String my_string, int[] indices) {
        StringBuilder sb = new StringBuilder(my_string);
        
        // indices 배열을 오름차순으로 정렬
        Arrays.sort(indices);

        // 인덱스를 역순으로 순회하여 글자 제거
        for (int i = indices.length - 1; i >= 0; i--) {
            int index = indices[i];
            sb.deleteCharAt(index);
        }

        return sb.toString();
    }
}
