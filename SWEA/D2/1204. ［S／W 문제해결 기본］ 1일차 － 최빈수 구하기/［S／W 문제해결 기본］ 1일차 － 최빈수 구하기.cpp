#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {   
        int n;
        cin >> n;
        unordered_map<int, int> m;
        vector<int> ans;
        int mode = -1;
        for (int i = 1; i <= 1000; i++) {
            int score;
            cin >> score;
            m[score]++;
            if (m[score] >= m[mode]) {
                if (m[score] == m[mode] && score > mode) {
                    mode = score;
                    continue;
                }
                mode = score;
            }
        }
        cout << '#' << n << ' ' << mode << '\n';
    }
    return 0;
}