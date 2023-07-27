#include<bits/stdc++.h>
using namespace std;
vector<int> primes;

vector<int> sieve(int n, int k) {
    int cnt = 0;
    vector<bool> state(n+1, true);
    state[1] = false;
    for(int i = 1; i <= n; i++) {
        if(!state[i]) {
            continue;
        }
        for(int j = i; j <= n; j = j + i) {
            if(!state[j]) {
                continue;
            }
            state[j] = false;
            cnt++;
            if (cnt == k) {
                cout << j;
                exit(0);
            }
        }
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    sieve(n, k);

}