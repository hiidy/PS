#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, x, y, k;
int row[3];
int col[4];
int board[21][21];

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }
    return true;
}

void right() {
    int tmp = row[2];
    row[2] = row[1];
    row[1] = row[0];
    row[0] = col[3];
    col[3] = tmp;
    col[1] = row[1];
}

void left() {
    int tmp = row[0];
    row[0] = row[1];
    row[1] = row[2];
    row[2] = col[3];
    col[3] = tmp;
    col[1] = row[1];
}

void up() {
    int tmp = col[0];
    col[0] = col[1];
    col[1] = col[2];
    col[2] = col[3];
    col[3] = tmp;
    row[1] = col[1];
}

void down() {
    int tmp = col[3];
    col[3] = col[2];
    col[2] = col[1];
    col[1] = col[0];
    col[0] = tmp;
    row[1] = col[1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int input;
        cin >> input;
        if (input == 1) {
            if (!isValid(x, y + 1)) {
                continue;
            }
            right();
            y++;
        } else if (input == 2) {
            if (!isValid(x, y - 1)) {
                continue;
            }
            left();
            y--;
        } else if (input == 3) {
            if (!isValid(x - 1, y)) {
                continue;
            }
            up();
            x--;
        } else if (input == 4) {
            if (!isValid(x + 1, y)) {
                continue;
            }
            down();
            x++;
        }

        if (board[x][y] != 0) {
            col[1] = board[x][y];
            row[1] = board[x][y];
            board[x][y] = 0;
        } else {
            board[x][y] = col[1];
        }

        cout << col[3] << '\n';
    }
    
    return 0;
}