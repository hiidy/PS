#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    int cnt = 0;
    cin >> n >> k;

    list<int> L = {};


    for(int i = 1; i <=n; i++) {
        L.push_back(i);
    }
    auto cursor = L.begin();
    cout << '<';
    while(!L.empty()) {
        for(int i = 0; i < k -1; i ++) {
            if (cursor == L.end()) {
                cursor ++;
            }
            cursor ++;
            if (cursor == L.end()) {
                cursor ++;
            }
        }
        if (cnt == n-1) {
            cout << *cursor;
            break;
        }
        cout << *cursor << ',' << " ";
        cursor = L.erase(cursor);
        cnt++;
    }
    cout << '>';
}