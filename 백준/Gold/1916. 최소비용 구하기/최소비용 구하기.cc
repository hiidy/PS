#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int v, e;
int st, en;
int d[1002];
vector<pair<int, int>> adj[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    cin >> st >> en;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    fill(d, d + v + 1, INF);
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

    cout << d[en];
}
