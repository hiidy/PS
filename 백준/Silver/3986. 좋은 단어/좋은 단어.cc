#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int ans = 0;
    cin >> n;

    while(n--) {
        string s;
        cin >> s;
        stack<char> stk;
        for(auto c : s) {
            if((!stk.empty()) && stk.top() == c) {
                stk.pop();
                continue;
            } 
            stk.push(c);
            // cout << stk.top() << "\n";
        }

        if(stk.empty()) {
            ans++;
        }
    }
    cout << ans;
}