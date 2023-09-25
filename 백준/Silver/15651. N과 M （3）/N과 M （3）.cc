#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int k) {
    if(k == m) { //자리수 m을 만족하면 base condition 발동
        for(int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) { // 중복 순열 문제이기 때문에 isUsed가 필요 없다.
        arr[k] = i;
        func(k+1);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);

}