#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int arr[1002][1002];
int dp[1002][1002];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] =
                max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + arr[i][j];
        }
    }

    cout << dp[n][m];
}