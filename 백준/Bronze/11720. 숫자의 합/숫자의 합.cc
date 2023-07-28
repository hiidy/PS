#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int sum =0;
    cin >> t;
    while(t--) {
        string input;
        cin >> input;
        for(auto s : input) {
            sum+=s-'0';
        }
    }
    cout << sum;
}
