#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[101];
ll dp[101][101];
ll ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[1][arr[1]] = 1;
    for(int i = 2; i <= n-1; i++) {
        for(int j = 0; j <=20; j++)  {
            if(j+arr[i] <= 20) {
                dp[i][j+arr[i]] += dp[i-1][j];
            }
            if(j-arr[i] >= 0)
                dp[i][j-arr[i]] += dp[i-1][j];
        }
    }
    ans = (ll)dp[n-1][arr[n]];
    cout << ans;

}