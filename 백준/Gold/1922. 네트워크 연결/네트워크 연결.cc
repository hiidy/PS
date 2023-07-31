#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<int> p(100001, -1);
tuple<int, int, int> edge[100001];

int find(int x) {
    if (p[x] < 0) {
        return x;
    }
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) {
        return 0;
    }
    if (p[u] == p[v]) {
        p[u]--;
    }
    if (p[u] > p[v]) {
        p[u] = v;
    } else {
        p[v] = u;
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v;
    cin >> e;

    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    sort(edge, edge + e);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b)) {
            continue;
        }
        ans += cost;
        cnt++;
        if (cnt == v - 1) {
            break;
        }
    }

    cout << ans;
}