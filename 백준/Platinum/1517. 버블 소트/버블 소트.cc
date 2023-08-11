#include <bits/stdc++.h>

using namespace std;

int n;
typedef long long ll;
vector<pair<int, int>> v;

void init(vector<ll> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;
    } else {
        int mid = (start + end) / 2;
        init(tree, 2 * node, start, mid);
        init(tree, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

ll query(vector<ll> &tree, int node, int start, int end, int left,
          int right) {
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

void update(vector<ll> &tree, int node, int start, int end, int index,
            int val) {
    if (index < start || index > end) {
        return;
    }
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(tree, 2 * node, start, mid, index, val);
    update(tree, 2 * node + 1, mid + 1, end, index, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int H = int(ceil(log2(n)));
    int tree_size = 1 << (H + 1);
    vector<ll> tree(tree_size);
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back({input, i});
    }
    init(tree, 1, 0, n-1);
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int target = v[i].second;
        ans += query(tree, 1, 0, n - 1, 0, target) - 1;
        update(tree, 1, 0, n - 1, target, 0);
    }

    cout << ans;
}
