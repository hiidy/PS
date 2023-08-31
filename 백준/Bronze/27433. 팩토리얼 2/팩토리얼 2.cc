#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

ll func(int n) {
    if (n == 1)
        return 1;
    ll val = func(n - 1);
    val = val * (n);
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n == 0) {
        cout << 1;
        return 0;
    }
    cout << func(n);
}