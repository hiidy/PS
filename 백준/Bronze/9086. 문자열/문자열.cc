#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    cin >> t;
    while (t--) {
        cin >> input;
        int string_len = input.length();
        cout << input[0] << input[string_len - 1] << "\n";
    }
}