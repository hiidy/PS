#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[101];
ll dp[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}