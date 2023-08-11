#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

void init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    } else {
        init(a, tree, 2*node, start ,(start+end)/2);
        init(a, tree, 2*node+1, (start+end)/2+1 ,end);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

ll query(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if(left > end || right <start) {
        return 1e9+1;
    }
    if(left<=start && end<=right) {
        return tree[node];
    }
    ll lsum = query(tree, 2*node, start ,(start+end)/2, left, right);
    ll rsum = query(tree, 2*node+1, (start+end)/2+1 ,end, left, right);
    return min(lsum, rsum);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    int H = int(ceil(log2(n)));
    int tree_size = 1 << (H+1);
    vector<ll> tree(tree_size);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a, tree, 1, 0, n-1);
    while(m--) {
        int left, right;
        cin >> left >> right;
        cout << query(tree, 1, 0, n-1, left-1, right-1) << "\n";
    }
}