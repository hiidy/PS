#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        string s;
        bool flag = 1;
        getline(cin, s);
        stack<char> stk;
        
        if(s == ".") {
            break;
        }
        for(auto c : s) {
            if(c == '[' || c == '(') {
                stk.push(c);
            } else if(c == ')') {
                if (stk.empty() || stk.top() == '[') {
                    flag = 0;
                    break;
                } else if(stk.top() == '(') {
                    stk.pop();
                }
            } else if(c == ']') {
                if (stk.empty() || stk.top() == '(') {
                    flag = 0;
                    break;
                }else if(stk.top() == '[') {
                    stk.pop();
                }
            }
        }
        
        if(!stk.empty()) {
            flag = 0;
        }
        if(flag) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }
}