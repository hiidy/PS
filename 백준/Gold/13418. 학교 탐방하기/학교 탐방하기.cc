#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
vector<int> p(1002, -1);

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

vector<tuple<int, int, int>> edge;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int result_1 = 0;
    int cnt_1 = 0;
    int result_2 = 0;
    int cnt_2 = 0;
    for (int i = 0; i < m + 1; i++) {
        int cost, a, b;
        cin >> a >> b >> cost;
        if(cost == 1) {
            cost = 0;
        } else {
            cost = 1;
        }
        if (a == 0 && b == 1) {
            is_diff_group(a, b);
            result_1 += cost;
            result_2 += cost;
            cnt_1++;
            cnt_2++;
        }
        edge.push_back({cost, a, b});
    }
    sort(edge.begin(), edge.end());

    for (auto e : edge) {
        int cost, a, b;
        tie(cost, a, b) = e;
        if (!is_diff_group(a, b))
            continue;
        result_1 += cost;
        cnt_1++;
        if (cnt_1 == n) {
            break;
        }
    }
    ans -= result_1 * result_1;

    p.assign(n + 2, -1);
    is_diff_group(0, 1);
    sort(edge.begin(), edge.end(), greater<>());

    for (auto e : edge) {
        int cost, a, b;
        tie(cost, a, b) = e;
        if (!is_diff_group(a, b))
            continue;
        result_2 += cost;
        cnt_2++;
        if (cnt_2 == n) {
            break;
        }
    }

    ans += result_2 * result_2;

    cout << ans;
}