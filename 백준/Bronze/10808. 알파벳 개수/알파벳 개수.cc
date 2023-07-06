#include <iostream>

using namespace std;

int main(void) {
    int array[26] = {};
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(auto c : s) {
        array[c - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        cout << array[i] << ' ';
    }
}