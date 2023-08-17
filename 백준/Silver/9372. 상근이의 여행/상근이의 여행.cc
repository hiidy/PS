#include<iostream>
using namespace std;
int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        int v, e;
        cin >> v >> e;
        for(int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
        }
        cout << v-1 << "\n";
    }

}