#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int v, e, x;
vector<pair<int, int>> adj[1005];
const int INF = 1e9 + 1;

int dijk(int st, int en) {
    int d[1005];
    fill(d, d + v + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.X != d[cur.Y]) {
            continue;
        }
        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= nxt.X + d[cur.Y]) {
                continue;
            }
            d[nxt.Y] = nxt.X + d[cur.Y];
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    return d[en];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e >> x;
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    int ans = 0;
    for (int st = 1; st <= v; st++) {
        ans = max(ans, dijk(st, x) + dijk(x, st));
    }

    cout << ans;
}