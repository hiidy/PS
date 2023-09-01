#include<bits/stdc++.h>
using namespace std;

int n;
int board[2200][2200];
int cnt[3];

bool check(int x, int y, int n) { //x, y 를 기준으로 n길이만큼 정사각형 배열 검사 true면 모두 같은 수로 되어있다.
    for(int i = x; i < x+n; i++) {
        for(int j = y; j < y+n; j++) {
            if(board[x][y] != board[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}



void func(int x, int y, int n) { //x와 y를 기준으로 n의 길이의 정사각형

    if(check(x, y, n)) {  //base condition 종이가 모두 같은 수로 되어있는지 확인. 
        cnt[board[x][y] + 1] += 1;
        return;  //모두 같은 수로 되어있으면 board[x][y]의 개수를 n*n만큼 더해주기
    }

    int tmp = n/3;
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            func(x + i * tmp, y + j * tmp, tmp); // 1이 아닌경우 종이를 9개를 자른다. x, y를 기준으로  n/3길이만큼 늘어남.
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <n; j++) {
            cin >> board[i][j];
        }
    }
    func(0, 0, n);
    for(int i = 0; i < 3; i++) {
        cout << cnt[i] << "\n";
    }
}