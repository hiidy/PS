#include <bits/stdc++.h>
using namespace std;

int arr[1000003];
vector<int> lis;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    lis.push_back(arr[0]);
    auto cursor = lis.begin();
    for (int i = 1; i < n; i++) {
        // cout << *cursor << " ";
        if (*cursor < arr[i]) {
            lis.push_back(arr[i]);
            cursor = lis.end() -1 ;
        } else {
            *lower_bound(lis.begin(), lis.end(), arr[i]) = arr[i];
        }

        // for(auto s : lis) {
        //     cout << s << " ";
        // cout << "\n";
    }
    cout << lis.size();
}
