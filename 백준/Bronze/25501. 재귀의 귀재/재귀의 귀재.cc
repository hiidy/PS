#include <bits/stdc++.h>
using namespace std;

int t;
int cnt = 0;

int recursion(string &s, int l, int r) {
    cnt++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(string &s) { return recursion(s, 0, s.length() - 1); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        string input;
        cin >> input;
        cout << isPalindrome(input) << ' ' << cnt << "\n";
        cnt = 0;
    }
}