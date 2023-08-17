#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> p(100002, -1);
int n, m;

int find(int x) {
    if (p[x] < 0) return x;
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

tuple<int, int, int> edge[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    sort(edge, edge + m);
    int mx_edge = 0;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b))
            continue;
        mx_edge = max(mx_edge, cost);
        ans += cost;
        cnt++;
        if (cnt == n - 1) {
            break;
        }
    }

    cout << ans - mx_edge;
}