#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10]; //출력할 수열을 기록하는 배열
int num[10]; //입력받은 수
bool isUsed[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }
    int prev = 0; //바로 이전 수열의 마지막항을 기록
    for (int i = 0; i < n; i++) {
        if (isUsed[i])
            continue;
        if (num[i] == prev)
            continue;
        arr[k] = num[i];
        prev = arr[k];
        isUsed[i] = true;
        func(k + 1);
        isUsed[i] = false;
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