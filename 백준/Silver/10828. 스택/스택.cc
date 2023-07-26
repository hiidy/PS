#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> stk;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int t;
            cin >> t;
            stk.push(t);
        } else if (s == "pop"){
            if(!stk.empty()) {
                cout << stk.top() << "\n";
                stk.pop();
            } else {
                cout << -1 << "\n";
            }
        } else if (s == "size") {
            cout << stk.size() << "\n";
        } else if (s == "empty") {
            if (stk.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (s == "top") {
            if (stk.empty()) {
                cout << -1 << "\n";
            } else {
                cout << stk.top() << "\n";
            }
        }
    }
}