#include <bits/stdc++.h>
using namespace std;
int n;
int deg[501];
int dp[501];
queue<int> q;
vector<int> adj[501];
int cost[501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        while (true) {
            int input;
            cin >> input;
            if (input == -1) {
                break;
            }
            adj[input].push_back(i);
            deg[i]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
            dp[i] = cost[i];
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            dp[nxt] = max(dp[nxt], dp[cur] + cost[nxt]);
            if (deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << "\n";
    }
}