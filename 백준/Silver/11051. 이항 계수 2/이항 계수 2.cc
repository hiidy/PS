#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int j = 1; j < i; j++) {
            dp[i][j] = (dp[i-1][i-j] + dp[i-1][j]) % 10007 ;
        }
    }

    cout << dp[n][k];

}