#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

vector<int> p(100005, -1);
int n, m;

int find(int x) {
    if (p[x] < 0) {
        return x;
    }
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return 0;
    if (p[u] == p[v])
        p[u]--;
    if (p[u] < p[v])
        p[v] = u;
    else
        p[u] = v;
    return 1;
}

vector<tuple<int, int, int>> edge;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll total = 0;
    for (int i = 0; i < m; i++) {
        int cost, a, b;
        cin >> a >> b >> cost;
        edge.push_back({cost, a, b});
        total += cost;
    }

    sort(edge.begin(), edge.end());
    ll ans = 0;
    int cnt = 0;
    for (auto e : edge) {
        int cost, a, b;
        tie(cost, a, b) = e;
        if (!is_diff_group(a, b))
            continue;
        ans += cost;
        cnt++;
        if (cnt == m) {
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        if (find(i) != find(i + 1)) {
            cout << -1;
            return 0;
        }
    }
    cout << total - ans;
}