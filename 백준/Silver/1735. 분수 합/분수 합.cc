#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b%a, a);
}

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;

    int tmpa =(a1*b2 + a2*b1);
    int tmpb = b1*b2;
    int tmp_gcd = gcd(tmpa, tmpb);
    cout << tmpa/tmp_gcd  << " " << tmpb/tmp_gcd;

}