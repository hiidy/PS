#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10]; //K 번째까지의 수열을 기록할 배열

void func(int k) { //func의 의미 : 현재 k개의 수를 선택했다.
    if (k == m) { //현재 m개의 수를 선택하면 base condition
        for (int i = 0; i < m; i++) { 
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) { 
        if (k > 0) {
            if (arr[k - 1] > i) // 비 내림차순이기 때문에 이전 수열(arr[k-1])은 i보다 작거나 같아야한다.
                continue;
        }
        arr[k] = i; 
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}