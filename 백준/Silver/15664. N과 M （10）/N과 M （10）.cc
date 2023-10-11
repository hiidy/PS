#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int arr[10];
bool isUsed[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }
    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (isUsed[i]) {
            continue;
        }
        if (prev == num[i]) {
            continue;
        }
        if (k > 0) {
            if (arr[k - 1] > num[i]) {
                continue;
            }
        }
        arr[k] = num[i];
        prev = arr[k];
        isUsed[i] = 1;
        func(k + 1);
        isUsed[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    func(0);
}