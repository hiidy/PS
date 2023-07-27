#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    } else {
        init(a, tree, 2*node, start, (start+end) /2);
        init(a, tree, 2*node + 1, (start+end)/2 +1, end);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

ll query(vector<ll> &tree, int node, int start, int end, int left, int right) {
    // 안겹칠때
    if (left > end || right < start) {
        return 0;
    }
    // 답이 구간을 포함할 때
    if(left <= start && end <= right) {
        return tree[node];
    }

    //탐색을 더 이어나가야됨
    ll lsum = query(tree, 2 * node, start, (start+end) / 2, left, right);
    ll rsum = query(tree, 2 * node + 1, (start + end)/ 2 + 1, end , left, right);

    return lsum + rsum;
}

void update(vector<ll> &a, vector<ll> &tree, int node, int start, int end, int index, ll val) {
    if (index < start || index > end) {
        return;
    }

    if (start == end) {
        a[index] = val;
        tree[node] = val;
        return;
    }

    update(a, tree, 2*node, start, (start+end) / 2, index, val);
    update(a, tree, 2*node + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = tree[2*node] + tree[2*node + 1];
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    int H = int(ceil(log2(n)));
    int tree_size = 1 << (H+1);
    vector<ll> tree(tree_size);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a, tree, 1, 0, n-1);
    for(int i = 0; i < q; i++) {
        int index, left, right;
        ll val;
        cin >> left >> right >> index >> val;
        if(left < right) {
            cout << query(tree, 1, 0, n-1, left-1, right-1) << "\n";
        } else {
            cout << query(tree, 1, 0, n-1, right-1, left-1) << "\n";
        }
        update(a, tree, 1, 0, n-1, index-1, val);

        }
    }
