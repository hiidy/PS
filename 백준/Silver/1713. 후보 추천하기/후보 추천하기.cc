#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;



int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<pair<int, int> > student; // 학생 idx, 추천수
    
    for(int i = 0; i < m; i++) {
        int input;
        int min_num = 0;
        int min_value = 1000001;
        cin >> input;
        bool flag=0;

        //추천이 이미 되었는지 확인
        for(int i = 0 ; i < student.size(); i++) {
            // 추천이 이미 되었다.
            if(input == student[i].first) {
                student[i].second++;
                flag = 1;
                break;
            } 
        }

        if(flag != 1) {
            if(student.size() < n) {
                student.push_back(make_pair(input, 1));
            } else {
                //최솟값 찾기
                for(int i = 0; i < student.size(); i++) {
                    min_value = min(min_value, student[i].second);
                }
                //최솟값 개수 찾기
                for(int i = 0; i < student.size(); i++) {
                    if(student[i].second == min_value) {
                        student.erase(student.begin() + i);
                        break;
                    }
                }
                student.push_back(make_pair(input, 1));
            }
        }
    }
    sort(student.begin(), student.end());
    for(int i = 0; i < student.size(); i++) {
        cout << student[i].first << " ";
    }

}