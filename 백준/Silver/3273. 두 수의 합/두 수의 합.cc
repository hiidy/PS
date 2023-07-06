#include <iostream>

using namespace std;
int number[1000001] = {};


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> number[i];
    }
    cin >> x;
    bool count[2000000];

    int ans=0;

    for(int i = 0; i < n; i++) {
        if(x - number[i] > 0 && count[x - number[i]]) {
            ans++;
        } else {
        count[number[i]] = 1;
        }
    }

    cout << ans;
}