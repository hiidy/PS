#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>

typedef long long ll;
using namespace std;

int n, m, k;
const int MAX = 100002;
const ll INF = 0x7f7f7f7f7f7f;
ll d[MAX];
vector<pair<int, int>> adj[MAX];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[v].push_back({w, u});
    }
    fill(d+1, d+1+n, INF);
    
    while(k--) {
        int input;
        cin >> input;
        d[input] = 0;
        pq.push({d[input], input});
    }

    while(!pq.empty()) {
        int u, v;
        ll w, dw;
        tie(w, u) = pq.top();
        pq.pop();
        if(d[u] != w) continue;
        for(auto nxt : adj[u]) {
            tie(dw, v) = nxt;
            if(d[v]<=w+dw) continue;
            d[v] = w + dw;
            pq.push({d[v], v});
        }
    }
    int idx = max_element(d+1, d+1+n) - d;
    cout << idx << "\n" << d[idx];
    
}