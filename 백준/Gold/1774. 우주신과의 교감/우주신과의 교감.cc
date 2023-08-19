#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef long long ll;

vector<int> p(1002, -1);
int n, m;

int find(int x) {
    if (p[x] < 0)
        return x;
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

vector<pair<int, int>> v;
vector<tuple<ll, int, int>> edge;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    int cnt = 0;
    double ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            ll tmp = (ll)(v[i].X - v[j].X) * (v[i].X - v[j].X) +
                              (ll)(v[i].Y - v[j].Y) * (v[i].Y - v[j].Y);
            edge.push_back({tmp, i, j});
        }
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(is_diff_group(x-1, y-1))
            cnt++;
    }

    sort(edge.begin(), edge.end());

    for (auto e : edge) {
        ll cost;
        int a, b;
        tie(cost, a, b) = e;
        if (!is_diff_group(a, b))
            continue;
        ans += sqrt(cost);
        cnt++;
        if (cnt == n - 1) {
            break;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
}

