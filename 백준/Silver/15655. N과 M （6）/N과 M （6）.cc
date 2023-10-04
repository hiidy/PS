#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10]; // 사용할 수를 담아두는 배열
int arr[10]; // 조건에 해당하는 수열을 담아두고 출력할 배열
bool isUsed[10]; // 인덱스별 사용 유무를 기록

void func(int k) { // 현재까지 K개를 선택했을 때
    if (k == m) { //m개를 선택했을 때 base condition 발동
        for (int i = 0; i < m; i++) {
            cout << num[arr[i]] << ' '; //기록해 둔 idx에 따른 num의 배열 출력
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        if (k > 0) {
            if (num[arr[k - 1]] >= num[i]) //오름차순으로 정렬
                continue;
        }
        if (isUsed[i]) //사용된 idx면 continue
            continue;
        isUsed[i] = true;
        arr[k] = i; //k번째는 i 인덱스를 기록한다.
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
    sort(num, num + n); //사전 순으로 증가하기 위해서 sort
    func(0);
}
