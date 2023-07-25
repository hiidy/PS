#include<bits/stdc++.h>
using namespace std;
int n;
map<char, int> alphabet;

bool comp(pair<char, int> &a, pair<char, int> &b) {
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            char alpha = s[j];
            if(alphabet[alpha] != 0) {
                alphabet[alpha] += pow(10, (s.size() - j - 1));
            } else {
                alphabet[alpha] = pow(10, (s.size() - j - 1));
            }
        }
    }

    vector<pair<char, int> > v(alphabet.begin(), alphabet.end());
    sort(v.begin(), v.end(), comp);

    int num = 9;
    for(auto i : v) {
        ans += (num * i.second);
        num--;
    }
    cout << ans;
}