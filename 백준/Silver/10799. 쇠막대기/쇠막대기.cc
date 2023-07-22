#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> stk;
    int ans = 0;
    string s;
    cin >> s;


    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            stk.push(s[i]);
        } else if(s[i] == ')') {
            if(s[i-1] == '(') {
                stk.pop();
                ans += stk.size();
            } else if(s[i-1] == ')') {
                stk.pop();
                ans ++;
            }
        }
    }
    cout << ans;

}