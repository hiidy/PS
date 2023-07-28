#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[30][30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        int ret = 1;
        cin >> k >> n;
        for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int j = 1; j < i; j++) {
            dp[i][j] = (dp[i-1][i-j] + dp[i-1][j]);
        }
    }
        cout << dp[n][k] << "\n";
        
    }
}