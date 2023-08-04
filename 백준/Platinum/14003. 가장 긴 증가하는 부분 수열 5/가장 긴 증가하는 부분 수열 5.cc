#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000002;
int arr[MAX];
vector<int> v;
int n;
int dp[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fill(dp, dp + n, 1);
    v.push_back(arr[0]);
    auto cursor = v.begin();
    for (int i = 1; i < n; i++) {
        if (*cursor < arr[i]) {
            v.push_back(arr[i]);
            cursor = v.end() - 1;
            dp[i] = v.size();
        } else {
            dp[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
            *lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
        }
    }
    deque<int> q;
    int cnt = v.size();
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] == cnt) {
            q.push_front(arr[i]);
            cnt--;
        }
    }
    cout << v.size() << "\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop_front();
    }
}
