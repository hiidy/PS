#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define X first
#define Y second

using namespace std;

vector<int> p(102, -1);
int n;

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

vector<tuple<double, int, int>> edge;
vector<pair<double, double>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (i == j)
                continue;
            double tmp = sqrt((v[i].X - v[j].X) * (v[i].X - v[j].X) +
                              (v[i].Y - v[j].Y) * (v[i].Y - v[j].Y));
            edge.push_back({tmp, i, j});
        }
    }

    sort(edge.begin(), edge.end());
    double ans = 0;
    int cnt = 0;
    for (auto e : edge) {
        double cost;
        int a, b;
        tie(cost, a, b) = e;
        if (!is_diff_group(a, b))
            continue;
        ans += cost;
        cnt++;
        if (cnt == n - 1) {
            break;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
}