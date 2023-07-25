#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll cnt;
vector<int> ab;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    // ab 복잡도 4000^2

    for(int i = 0; i < n; i++) {
        for(int j =0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
        }
    }
    
    sort(ab.begin(), ab.end());

    for(int i = 0; i < n; i++) {
        for(int j =0; j < n; j++) {
            int target = -(c[i] + d[j]);
            auto Pair = equal_range(ab.begin(), ab.end(), target);
            cnt += Pair.second-Pair.first;
        }
    }
    cout << cnt;
}