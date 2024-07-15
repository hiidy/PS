#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }

        int max_num = 0;
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                int area = 0;
                for (int a = 0; a < m; a++) {
                    for (int b = 0; b < m; b++) {
                        area += v[i + b][j + a];
                    }
                }
                if (max_num < area) {
                    max_num = area;
                }
            }
        }
        cout << '#' << test_case << ' ' << max_num << '\n';



    }
    return 0;
}