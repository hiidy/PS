#include <vector>
#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;
const int MOD = 1000000007;

void init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    } else {
        init(a, tree, 2*node, start, (start+end)/2);
        init(a, tree, 2*node+1, (start+end)/2+1, end);
        tree[node] = tree[2*node] * tree[2*node+1]%MOD;
    }

}

ll query(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return 1;
    }
    if(left<=start && end<=right) {
        return tree[node];
    }
    ll lmul = query(tree, 2*node, start, (start+end)/2, left, right);
    ll rmul = query(tree, 2*node+1, (start+end)/2+1, end, left, right);
    return lmul*rmul%MOD;
}

void update(vector<ll> &a, vector<ll> &tree, int node, int start, int end, int index, ll val) {
    if(index <start || index > end) {
        return;
    }
    if(start == end) {
        a[index] = val;
        tree[node] = val;
        return;
    }
    update(a, tree, 2*node, start, (start+end)/2, index, val);
    update(a, tree, 2*node+1, (start+end)/2+1, end , index, val);
    tree[node] = tree[2*node] * tree[2*node+1] % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    int H = int(ceil(log2(n)));
    int tree_size = 1 << (H+1);
    vector<ll> tree(tree_size);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a, tree, 1, 0, n-1);
    int tmp = m + k;
    while(tmp--) {
        int input;
        cin >> input;
        if(input == 1) {
            int b;
            ll c;
            cin >> b >> c;
            update(a, tree, 1, 0, n-1, b-1, c);
        } else if(input == 2) {
            int b, c;
            cin >> b >> c;
            cout << query(tree, 1, 0, n-1, b-1, c-1) << "\n";
        }
    }
}