#include<bits/stdc++.h>
using namespace std;

int maxdp[2][3];
int mindp[2][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c, t;
    cin >> n;
    int j = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        maxdp[j][0] = max(maxdp[1-j][0], maxdp[1-j][1])+a;
        maxdp[j][1] = max({maxdp[1-j][0], maxdp[1-j][1], maxdp[1-j][2]}) + b ;
        maxdp[j][2] = max(maxdp[1-j][1], maxdp[1-j][2])+c;

        mindp[j][0] = min(mindp[1-j][0], mindp[1-j][1])+a;
        mindp[j][1] = min({mindp[1-j][0], mindp[1-j][1], mindp[1-j][2]}) + b ;
        mindp[j][2] = min(mindp[1-j][1], mindp[1-j][2])+c;

        if(j == 1) {
            j = 0;
        } else if(j == 0) {
            j = 1;
        }
    }
    if(n % 2 == 0) {
        t = 0;
    } else {
        t = 1;
    }
    
    cout << *max_element(maxdp[t], maxdp[t] + 3) << " " << *min_element(mindp[t], mindp[t] + 3);
}