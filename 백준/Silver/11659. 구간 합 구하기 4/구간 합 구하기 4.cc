#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int dp[MAX];
int arr[MAX];



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + arr[i];
    }
    while(m--) {
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i-1] << "\n";
    }

}