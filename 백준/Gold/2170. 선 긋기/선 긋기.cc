#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int n;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    int st = v[0].first;
    int en = v[0].second;
    for (int i = 1; i < n; i++) {
        if (v[i].first <= en) {
            if (v[i].second > en) {
                en = v[i].second;
            }
        } else {
            ans += (en - st);
            st = v[i].first;
            en = v[i].second;
        }
    }
    ans += (en - st);

    cout << ans;
}