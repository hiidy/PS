#include <bits/stdc++.h>
using namespace std;

int n;
int board[129][129];
int cnt[2];

bool check(int x, int y, int n) { // 한 변의 길이가 n인 정사각형을 check하기
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[x][y] != board[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void func(int x, int y, int n) {
    if (check(x, y, n)) {
        cnt[board[x][y]] += 1;
        return;
    }

    int tmp = n / 2; // check를 만족하지 못하면 종이 4개로 나누기
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(x + i * tmp, y + j * tmp, tmp);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    func(0, 0, n);
    cout << cnt[0] << "\n" << cnt[1];
}