#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        stack<char> stk;
        string s;
        bool flag = 1;
        cin >> s;
        for(auto c : s) {
            if(c == '(') {
                stk.push(c);
            } else if (c == ')') {
                if((stk.empty()) || stk.top() != '(') {
                    flag = 0;
                    break;
                } else if(stk.top() == '(') {
                    stk.pop();
                }
            }
        }

        if(!stk.empty()) {
            flag = 0;
        }
        if(flag) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}