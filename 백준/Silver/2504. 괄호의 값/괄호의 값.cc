#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    stack<char> stk;
    cin >> s;


    int mul = 1;
    int sum = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            mul*=2;
            stk.push(s[i]);
        } else if(s[i] == '[') {
            mul*=3;
            stk.push(s[i]);
        } else if(s[i] == ')') {
            if(stk.empty() || stk.top() != '(') {
                cout << 0;
                return 0;
            }
            if(s[i-1] == '(') {
                sum += mul;
            }
            if(stk.top() == '(') {
                stk.pop();
            }
            mul /= 2;
        } else if(s[i] == ']') {
            if(stk.empty() || stk.top() != '[') {
                cout << 0;
                return 0;
            }  
            if(s[i-1] == '[') {
                sum += mul;
            }
            if(stk.top() == '[') {
                stk.pop();
            }
            mul /= 3;
        }
    }

    if(stk.empty()) {
        cout << sum;
    } else {
        cout << 0;
    }
}