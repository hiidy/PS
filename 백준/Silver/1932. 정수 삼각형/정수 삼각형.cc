#include<bits/stdc++.h>
using namespace std;
int arr[501][501];
int dp[501][501];




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    //11 21 22 31 32 33 41 42 43 44
    
    for(int i = 1; i<=t; i++) {
        for(int j = 1; j <=i; j++) {
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];
    for(int i = 2; i<=t; i++) {
        for(int j = 1; j <=i; j++) {
            dp[i][j] = max(dp[i-1][j-1] + arr[i][j] , dp[i-1][j] + arr[i][j]);
        }
    }
    cout << *max_element(dp[t]+1, dp[t] +1 + t);
}