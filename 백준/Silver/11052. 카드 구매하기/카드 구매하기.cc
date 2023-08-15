#include<iostream>
using namespace std;

int dp[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <=n; i++) {
        cin >> dp[i];
    }

    for(int i = 1; i <=n; i ++) {
        for(int j = 1; j < i/2+1; j++) {
            dp[i] = max(dp[i], dp[i-j]+dp[j]);
        }
    }
    cout << dp[n];
}