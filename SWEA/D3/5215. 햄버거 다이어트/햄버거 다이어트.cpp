#include<iostream>

using namespace std;

int t[1002];
int k[1002];
int dp[30][10005];

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {   
        int n, l;
        cin >> n >> l;
        
        for (int i = 0; i < n; i++) {
            cin >> t[i] >> k[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= l; j++) {
                if (k[i - 1] <= j) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - k[i - 1]] + t[i - 1]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
                
            }
        }

        cout << '#' << test_case << ' ' << dp[n][l] << '\n';

    }
    return 0;
}