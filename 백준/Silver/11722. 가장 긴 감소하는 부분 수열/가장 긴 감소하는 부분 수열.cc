#include <algorithm>
#include <iostream>

using namespace std;

int n;
int dp[1002];
int arr[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= n; j++) {
            if (arr[i] < arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp + 1, dp + 1 + n);
}