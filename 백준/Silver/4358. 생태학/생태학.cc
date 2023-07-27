#include<bits/stdc++.h>
using namespace std;

map<string, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(4);
    int total = 0;
    string str;

    while(getline(cin, str)) {
        total++;
        m[str] += 1;
    }

    for(auto s = m.begin(); s != m.end(); s++) {
        cout << s->first << " " <<  (double)(s->second) / total *100 << "\n";
    }
}