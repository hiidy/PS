#include <algorithm>
#include <iostream>
using namespace std;

int arr[10002];
int dp[10002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[2] + dp[1];
    for (int i = 3; i <= n; i++) {
        dp[i] = max({arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3], dp[i-1]});
    }

    cout << *max_element(dp + 1, dp + 1 + n);
}