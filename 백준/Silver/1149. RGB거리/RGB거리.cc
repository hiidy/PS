#include<bits/stdc++.h>
using namespace std;
int cost[1001][3];
int dp[1001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    
    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];


    for(int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i-1][1] + cost[i][0], dp[i-1][2] + cost[i][0]);
        dp[i][1] = min(dp[i-1][0] + cost[i][1], dp[i-1][2] + cost[i][1]);
        dp[i][2] = min(dp[i-1][0] + cost[i][2], dp[i-1][1] + cost[i][2]);
    }

    
    cout << *min_element(dp[n], dp[n]+3);
}