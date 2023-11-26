#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[1002];
bool vist[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    // bfs로 탐색
    for (int i = 1; i <= v; i++) {
        if (vist[i] == 1) {
            continue;
        }
        ans++;
        queue<int> q;
        q.push(i);
        vist[i] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt: adj[cur]) {
                if (vist[nxt]) {
                    continue;
                }
                q.push(nxt);
                vist[nxt] = true;
            }
        }
    }
    cout << ans;
}

