#include <iostream>
using namespace std;

int n, k;
int coin[102];
int dp[10002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }

    cout << dp[k];
}