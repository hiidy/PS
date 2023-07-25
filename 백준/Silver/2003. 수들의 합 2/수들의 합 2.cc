#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int cnt = 0;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int end = 0;
    int sum = 0;
    for(int start = 0; start < n; start++) {
        while(sum < m && end < n) {
            sum += arr[end];
            end++;
        }
        if(sum == m) {
            cnt ++;   
        }
        sum -= arr[start]; 
    }

    cout << cnt;

}