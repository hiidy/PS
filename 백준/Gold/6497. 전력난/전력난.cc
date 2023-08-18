#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> p(200002, -1);

int n, m;

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

vector<tuple<int, int, int>> edge;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        p.assign(n+1, -1);
        vector<tuple<int, int, int>> edge;
        int total = 0;    
        cin >> n >> m;
        if (n == 0 && m == 0) {
            return 0;
        }
        for(int i = 0; i < m; i++) {
            int cost, a, b;
            cin >> a >> b>> cost;
            total += cost;
            edge.push_back({cost, a, b});
        }

        sort(edge.begin(), edge.end());
        int cnt = 0;
        int ans = 0;
        for(auto e : edge) {
            int cost, a, b;
            tie(cost, a, b) = e;
            if(!is_diff_group(a, b)) continue;
            ans += cost;
            cnt++;
            if(cnt == m) {
                break;
            }
        }
        cout << total - ans << "\n";
    }
}