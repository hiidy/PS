#include <bits/stdc++.h>
using namespace std;
int arr[1026][1026];
int dp[1026][1026];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1] + arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        int sum = 0;
        cin >> a >> b >> c >> d;
        for (int start = a; start <= c; start++) {
            sum += dp[start][d] - dp[start][b - 1];
        }
        cout << sum << "\n";
    }
}