#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    } else {
        init(a, tree, 2*node, start, (start+end) /2);
        init(a, tree, 2*node + 1, (start + end) / 2 + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
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

void update(vector<ll> & a, vector<ll> &tree, int node, int start, int end, int index, ll val) {
    // index를 포함안해서 끝내기
    if (index < start || index > end) {
        return;
    }
    
    //index 찾음
    if (start == end) {
        a[index] = val;
        tree[node] = val;
        return ;
    }
    //못찾아서 탐색을 계속
    update(a, tree, 2*node,start, (start+end) / 2, index, val );
    update(a, tree, 2*node + 1,(start+end) / 2 + 1, end, index, val );
    tree[node] = tree[2*node] + tree[2*node + 1];

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
            int index;
            ll value;
            cin >> index >> value;
            update(a, tree, 1, 0, n-1, index - 1, value);
        } else if (input == 2) {
            int left, right;
            cin >> left >> right;
            cout << query(tree, 1, 0, n-1, left-1, right-1) << "\n";
        }

    }
}