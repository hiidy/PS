#include<bits/stdc++.h>
using namespace std;
int parent[1000001];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        parent[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<= n; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            merge(y, z);
        } else if(x == 1) {
            if(find(y) == find(z)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
}