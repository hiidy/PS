#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    cin >> input;
    for(int i = 0; i < input.length(); i++) {
        cout << input[i];
        if(i % 10 == 9) {
            cout << "\n";
        }
    }
}
