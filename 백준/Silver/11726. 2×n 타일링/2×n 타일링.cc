#include<bits/stdc++.h>
using namespace std;
int dp[1001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    dp[2] = 2;
    dp[1] = 1;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[n];
}