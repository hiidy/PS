#include <iostream>
using namespace std;

int n, k;
int weight[102];
int cost[102];
int dp[102][100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> cost[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= weight[i]) {
                dp[i][j] =
                    max(dp[i - 1][j], dp[i - 1][j - weight[i]] + cost[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][k];
}