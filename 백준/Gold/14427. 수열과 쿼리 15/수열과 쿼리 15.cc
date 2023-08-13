#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
const int INF = 1e9 + 1;
vector<int> tree;
vector<int> a;

int n, m;

int minIdx(int x, int y) {
    if (a[x] == a[y]) {
        return min(x, y);
    }
    if (a[x] > a[y]) {
        return y;
    } else {
        return x;
    }
}

void init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
    } else {
        int mid = (start + end) / 2;
        init(a, tree, 2 * node, start, mid);
        init(a, tree, 2 * node + 1, mid + 1, end);
        tree[node] = minIdx(tree[2 * node], tree[2 * node + 1]);
    }
}

// int query(vector<int> &tree, int node, int start, int end, int left,
//           int right) {
//     if (left > end || right < start) {
//         return INF;
//     }
//     if (left <= start && end <= right) {
//         return tree[node];
//     }
//     int mid = (start + end) / 2;
//     int lsum = query(tree, 2 * node, start, mid, left, right);
//     int rsum = query(tree, 2 * node + 1, mid + 1, end, left, right);
//     return minIdx(lsum, rsum);
// }

void update(vector<int> &a, vector<int> &tree, int node, int start, int end,
            int index, int val) {
    if (index < start || index > end) {
        return;
    }
    if (start == end) {
        a[index] = val;
        tree[node] = start;
        return;
    }
    int mid = (start + end) / 2;
    update(a, tree, 2 * node, start, mid, index, val);
    update(a, tree, 2 * node + 1, mid + 1, end, index, val);
    tree[node] = minIdx(tree[2 * node], tree[2 * node + 1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    int H = int(ceil(log2(n)));
    int tree_size = 1 << (H + 1);
    tree.resize(tree_size);
    init(a, tree, 1, 0, n - 1);
    while (m--) {
        int input;
        cin >> input;
        if (input == 1) {
            int b, c;
            cin >> b >> c;
            update(a, tree, 1, 0, n - 1, b - 1, c);
        } else if (input == 2) {
            cout << tree[1] + 1 << "\n";
        }
    }
}