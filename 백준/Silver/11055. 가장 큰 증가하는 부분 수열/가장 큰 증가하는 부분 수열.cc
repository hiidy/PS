#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    for (int i = 1; i <= n; i++) {
        dp[i] = arr[i];
        for (int j = 1; j <= i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    cout << *max_element(dp + 1, dp + 1 + n);
}