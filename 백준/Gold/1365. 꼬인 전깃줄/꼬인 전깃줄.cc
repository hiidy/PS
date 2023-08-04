#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int arr[100001];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    v.push_back(arr[0]);
    auto cursor = v.begin();
    for (int i = 1; i <= n; i++) {
        if (*cursor < arr[i]) {
            v.push_back(arr[i]);
            cursor = v.end() - 1;
        } else {
            *lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
        }
    }

    cout << (n - v.size());
}