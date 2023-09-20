 #include <bits/stdc++.h>
using namespace std;

bool isUsed1[40];
bool isUsed2[40];
bool isUsed3[40];
int n;
int ans = 0;

void func(int cur) {
    if (cur == n) {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isUsed1[i] || isUsed2[cur + i] || isUsed3[cur - i + n - 1]) {
            continue;
        }
        isUsed1[i] = 1;
        isUsed2[cur + i] = 1;
        isUsed3[cur - i + n - 1] = 1;
        func(cur + 1);
        isUsed1[i] = 0;
        isUsed2[cur + i] = 0;
        isUsed3[cur - i + n - 1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << ans;
}
