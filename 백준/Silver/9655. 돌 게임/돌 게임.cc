#include <iostream>
using namespace std;

int n;
int dp[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
    }

    if (dp[n] % 2 == 0) {
        cout << "CY";
    } else {
        cout << "SK";
    }
}