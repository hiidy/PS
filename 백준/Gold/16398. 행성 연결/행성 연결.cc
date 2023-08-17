#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> p(1002, -1);
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
    if (p[u] < p[v]) {
        p[v] = u;
    } else {
        p[u] = v;
    }
    return 1;
}

vector<tuple<int, int, int>> edge;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            if (i == j)
                continue;
            edge.push_back({input, i, j});
        }
    }

    sort(edge.begin(), edge.end());
    int cnt = 0;
    long long ans = 0;
    for (auto e : edge) {
        int a, b, cost;
        tie(cost, a, b) = e;
        if (!is_diff_group(a, b))
            continue;
        ans += cost;
        cnt++;
        if (cnt == n - 1) {
            break;
        }
    }

    cout << ans;
}
