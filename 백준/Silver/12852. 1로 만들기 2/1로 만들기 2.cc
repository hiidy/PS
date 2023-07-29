#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000002;
int dp[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        if(i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3]+1);
        }
        if(i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2]+1);
        }
    }
    cout << dp[n] << "\n";
    cout << n << " ";

    while(n != 1) {
        if(dp[n] == dp[n-1] + 1) {
            n-=1;
            cout << n << " ";
        } else if(n%3 == 0 && dp[n] == dp[n/3] + 1) {
            n/=3;
            cout << n << " ";
        } else if(n%2 == 0 && dp[n] == dp[n/2] + 1) {
            n/=2;
            cout << n << " ";
        }
    }
}