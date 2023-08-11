#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
const int INF = 1e9 + 1;

void init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        init(a, tree, 2 * node, start, mid);
        init(a, tree, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

void init2(vector<int> &a, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        init2(a, tree, 2 * node, start, mid);
        init2(a, tree, 2 * node + 1, mid + 1, end);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

int query(vector<int> &tree, int node, int start, int end, int left,
          int right) {
    if (left > end || right < start) {
        return INF;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int lsum = query(tree, 2 * node, start, mid, left, right);
    int rsum = query(tree, 2 * node + 1, mid + 1, end, left, right);

    return min(lsum, rsum);
}

int query2(vector<int> &tree, int node, int start, int end, int left,
           int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int lsum = query2(tree, 2 * node, start, mid, left, right);
    int rsum = query2(tree, 2 * node + 1, mid + 1, end, left, right);

    return max(lsum, rsum);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int H = int(ceil(log2(n)));
    int tree_size = 1 << (H + 1);
    vector<int> tree_min(tree_size);
    vector<int> tree_max(tree_size);
    init(a, tree_min, 1, 0, n - 1);
    init2(a, tree_max, 1, 0, n - 1);
    while (m--) {
        int left, right;
        cin >> left >> right;
        cout << query(tree_min, 1, 0, n - 1, left - 1, right - 1) << " "
             << query2(tree_max, 1, 0, n - 1, left - 1, right - 1) << "\n";
    }
}
