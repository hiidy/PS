#include<bits/stdc++.h>
using namespace std;

int MAX = 1000002;

vector<bool> sieve(MAX, true);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve[1] = false;
    for(int i = 1; i <= MAX; i++) {
        if(!sieve[i]) {
            continue;
        }
        for(int j = i + i; j <=MAX; j = j + i) {
            sieve[j] = false;
            }
    }
    sieve[2] = false;
    while(true) {
        int n;
        cin >> n;
        if(n == 0) {
            return 0;
        }
        // n = a + b
        for(int b = n; b > 2; b--) {
            int a = n - b;
            if(sieve[b] && sieve[a]) {
                cout << n << " = " << a << " + " << b << "\n";
                break;
            }
        }

    }
}