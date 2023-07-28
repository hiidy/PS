#include<bits/stdc++.h>
using namespace std;
int arr[301];
int dp[10001];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[2] + dp[1];

    for(int i = 3; i <=n; i++) {
        dp[i] = max(dp[i-2]+arr[i], arr[i] + arr[i-1] + dp[i-3]);
    }

    cout << dp[n];
}