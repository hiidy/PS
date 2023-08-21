#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int n, m, k;
vector<int> p(1002, -1);

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

vector<tuple<int, int, int>> edge;
int cnt = 0;
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int input;
        cin >> input;
        is_diff_group(0, input);
        cnt++;
    }
    for(int i = 0; i < m; i++) {
        int cost, a, b;
        cin >> a >> b >> cost;
        edge.push_back({cost, a, b});
    }


    sort(edge.begin(), edge.end());
    for(auto e : edge) {
        int cost , a, b;
        tie(cost, a, b) = e;
        if(!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == n) {
            break;
        }
    }

    cout << ans;
}