#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000;
typedef long long ll;

int main() {
    ll x, y;
    cin >> x >> y;
    ll prob = y * 100 / x;
    int start = 0;
    int end = MAX;

    if(prob >= 99) {
        cout << -1;
        return 0;
    }
    
    while(start <= end ) {
        int mid = (start + end) / 2;
        int new_prob = (y+mid) * 100 / (x+mid);

        if(new_prob > prob) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        
        
    }
    cout << start;
}