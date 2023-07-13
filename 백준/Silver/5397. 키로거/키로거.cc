#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;

    cin >> t;

    for(int tc = 1; tc<=t; tc++) {
        list<char> L = {};
        string input;
        cin >> input;
        auto cursor = L.begin();

        for(auto s : input) {
            if (s == '<') {
                if (cursor == L.begin()) {
                    continue;
                }
                cursor--;
            } else if (s == '>') {
                if (cursor == L.end()) {
                    continue;
                }
                cursor++;
            } else if (s == '-') {
                if (cursor == L.begin()) {
                    continue;
                }
                cursor--;
                cursor = L.erase(cursor);
            } else {
                L.insert(cursor, s);
            }
        }

        for(auto s : L) {
            cout << s;
        }
        cout << "\n";
    }   
}