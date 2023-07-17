#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int cnt = 1;
    cin >> n;
    stack<int> stk;
    string ans;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        while (cnt <= input){
            stk.push(cnt);
            cnt++;
            ans += "+\n";
        }
        if (stk.top() == input) {
            stk.pop();
            ans += "-\n";
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << ans;

}