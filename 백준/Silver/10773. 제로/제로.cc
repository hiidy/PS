#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    int ans = 0;

    cin >> k;
    stack<int> stk;
    for(int i = 0; i < k; i++) {
        int t;
        cin >> t;
        if(t == 0) {
            stk.pop();
        } else {
            stk.push(t);
        }
    }

    while(!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }

    cout << ans;
}