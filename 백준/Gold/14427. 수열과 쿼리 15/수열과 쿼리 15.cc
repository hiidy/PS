#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
const int INF = 1e9 + 1;

int n, m;

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

void update(vector<int> &a, vector<int> &tree, int node, int start, int end,
            int index, int val) {
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
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    int H = int(ceil(log2(n)));
    int tree_size = 1 << (H + 1);
    vector<int> tree(tree_size);
    init(a, tree, 1, 0, n - 1);
    while (m--) {
        int input;
        cin >> input;
        if (input == 1) {
            int b, c;
            cin >> b >> c;
            update(a, tree, 1, 0, n - 1, b - 1, c);
        } else if (input == 2) {
            int result = query(tree, 1, 0, n - 1, 0, n - 1);
            cout << find(a.begin(), a.end(), result) - a.begin() + 1 << "\n";
        }
    }
}