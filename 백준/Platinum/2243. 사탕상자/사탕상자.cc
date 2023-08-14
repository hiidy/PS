#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000005;
vector<int> tree;

int query(vector<int> &tree, int node, int start, int end, int target) {
    if (start == end) {
        return start;
    }
    int mid = (start + end) / 2;
    if (tree[2 * node] >= target) {
        return query(tree, 2 * node, start, mid, target);
    } else {
        return query(tree, 2 * node + 1, mid + 1, end, target - tree[2 * node]);
    }
}

void update(vector<int> &tree, int node, int start, int end, int index,
            int val) {
    if (index < start || index > end) {
        return;
    }
    if (start == end) {
        tree[node] += val;
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
    int n;
    cin >> n;
    int H = int(ceil(log2(MAX)));
    int tree_size = 1 << (H + 1);
    tree.resize(tree_size);
    while (n--) {
        int input;
        cin >> input;
        if (input == 1) {
            int b;
            cin >> b;
            int result = query(tree, 1, 1, MAX, b);
            cout << result << "\n";
            update(tree, 1, 1, MAX, result, -1);
        } else {
            int b, c;
            cin >> b >> c;
            update(tree, 1, 1, MAX, b, c);
        }
    }
}