#include<bits/stdc++.h>
using namespace std;
int arr[51];

int main() {

    int m, k;
    int total = 0;
    cin >> m;
    for(int i = 0; i<m; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    cin >> k;

    double ans = 0;
    for(int i = 0; i < m; i++) {
        double ret = 1.0;
        if(arr[i] < k) {
            continue;
        }
        for(int j = 0; j < k; j++) {
            ret *= (double)(arr[i] - j) / (total-j);
        }
        ans += ret;
    }

    cout << fixed;
    cout.precision(15);
    cout << ans;
}