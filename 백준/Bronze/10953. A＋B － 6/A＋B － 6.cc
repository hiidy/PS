#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        char tmp;
        cin >> a >> tmp >> b;
        cout << a+b << "\n";
    }

}