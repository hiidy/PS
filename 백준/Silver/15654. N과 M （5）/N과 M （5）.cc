#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10]; // 주어진 수열을 담는 num
bool isUsed[10];
int arr[10];

void func(int k) { // 현재 까지 k개의 수를 택했음
    if (k == m) {  // m개를 모두 택했으면
        for (int i = 0; i < m; i++) {
            cout << num[arr[i]]
                 << ' '; // aar에 기록해둔 인덱스에 대응되는 수 출력
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) { // 0부터 n-1까지의 인덱스에 대해
        if (isUsed[i])
            continue;     // 아직 i가 사용되지 않았다면
        arr[k] = i;       // k번째 인덱스를 i로 정한다.
        isUsed[i] = true; // i가 사용되었다고 표시
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
    sort(num, num + n); // 사전순이라 수를 정렬
    func(0);
}
