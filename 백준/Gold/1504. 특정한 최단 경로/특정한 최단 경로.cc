#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;

ll n, e;
int v1, v2;
vector<pair<int, int>> adj[802];
ll d[802];
const int INF = 0x3f3f3f3f;

ll dijk(int st, int en) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    fill(d, d + n + 1, INF);
    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (d[cur.Y] != cur.X) {
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
    cin >> n >> e;
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    cin >> v1 >> v2;

    ll result1 = dijk(1, v1) + dijk(v1, v2) + dijk(v2, n);
    ll result2 = dijk(1, v2) + dijk(v2, v1) + dijk(v1, n);
    ll ans = min(result1, result2);

    if (ans >= INF) {
        cout << -1;
    } else {
        cout << ans;
    }
}
