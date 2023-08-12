#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
typedef long long ll;

int n, m;

void init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        init(a, tree, 2 * node, start, mid);
        init(a, tree, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

ll query(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    ll lsum = query(tree, 2 * node, start, mid, left, right);
    ll rsum = query(tree, 2 * node + 1, mid + 1, end, left, right);
    return lsum + rsum;
}

void update(vector<ll> &a, vector<ll> &tree, int node, int start, int end,
            int index, ll val) {
    if (index < start || index > end) {
        return;
    }
    if (start == end) {
        a[index] = val;
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(a, tree, 2 * node, start, mid, index, val);
    update(a, tree, 2 * node + 1, mid + 1, end, index, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<ll> a(n, 0);
    int H = int(ceil(log2(n)));
    int tree_size = 1 << (H + 1);
    vector<ll> tree(tree_size);
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        if (input == 0) {
            int b, c;
            cin >> b >> c;
            if(b < c) {
                cout << query(tree, 1, 0, n - 1, b - 1, c - 1) << "\n";
            } else {
                cout << query(tree, 1, 0, n - 1, c-1, b-1) << "\n";
            }
        } else {
            int b;
            ll c;
            cin >> b >> c;
            update(a, tree, 1, 0, n - 1, b - 1, c);
        }
    }
}