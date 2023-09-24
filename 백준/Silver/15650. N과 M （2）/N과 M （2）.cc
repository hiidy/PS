#include <bits/stdc++.h>
using namespace std;

int n, m;
bool isUsed[10]; //isUsed는 1부터 N까지의 자연수의 사용 여부이다.
int arr[10]; // arr은 m개 길이의 수열을 담는다.

void func(int k) { // k는 자리수
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i < n + 1; i++) {
        if (!isUsed[i]) {
            if (arr[k - 1] > i) //i는 이번에 사용 할 숫자이고 arr[k-1]는 이전에 사용한 수열의 수 이다.
                continue;       //i가 더 커야 오름차순이 성립한다.
            arr[k] = i;
            isUsed[i] = 1;
            func(k + 1);
            isUsed[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}