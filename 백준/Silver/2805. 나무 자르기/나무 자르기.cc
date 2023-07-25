#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    ll ans;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll start = 0;
    sort(arr, arr+n);
    ll end = arr[n-1];
    
    while(start <= end) {
        ll total = 0;
        ll mid = (start + end) / 2;
        for(int i = 0; i < n; i++) {
            if(arr[i] > mid) {
                total += (arr[i] - mid);
            }
        }
        if (total < m) {
            end = mid - 1;
        } else {
            start = mid + 1;
            ans = mid;
        }
    }
    cout << ans;
}