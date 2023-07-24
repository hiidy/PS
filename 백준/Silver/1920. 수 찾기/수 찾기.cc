#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    sort(arr, arr+n);
    for(int i = 0; i < m; i++) {
        int target;
        cin >> target;
        cout << binary_search(arr, arr+n, target) << "\n";
    }
}