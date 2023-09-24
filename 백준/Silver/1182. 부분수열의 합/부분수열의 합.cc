#include <bits/stdc++.h>
using namespace std;

int n, s;
int ans = 0;
int arr[21];

void func(int k, int sum) { // k는 arr을 순회할 때 순서 번호
    if (k == n) { // k == n이고 그 때까지 더한 합이 s와 같으면 ans++해준다.
        if (sum == s)
            ans++; // k == n이 되면 무조건 base condition이 발동되어야 하고
                   // ans++하는것은 추가
        return;
    }
    //
    func(k + 1, sum);
    func(k + 1, sum + arr[k]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    func(0, 0);
    if (s == 0) // ans == 0일 때 공집합을 제외하는 것을 주의하자. 양수인 부분수열만 고려함.
        ans--;
    cout << ans;
}
