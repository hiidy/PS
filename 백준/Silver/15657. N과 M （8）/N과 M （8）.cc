#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int arr[10];

void func(int k) { // 현재 k개까지 수열을 선택했다.
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << num[arr[i]] << ' ';
        }
        cout << "\n";
        return; // base condition에서 return 잊지 말기
    }
    for (int i = 0; i < n; i++) {
        if (k > 0) {
            if (num[arr[k - 1]] > num[i]) // 내림차순으로 정리하기 위해서
                continue; // 이전 수가 다음 수보다 크면 continue
        }
        arr[k] = i;
        func(k + 1);
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