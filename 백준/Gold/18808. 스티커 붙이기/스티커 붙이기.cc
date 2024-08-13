#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int r, c;
int paper[12][12];
int result[42][42];

void rotate() {
    int tmp[12][12];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[i][j] = paper[i][j];
        }
    }
    swap(r, c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            paper[i][j] = tmp[c - j - 1][i];
        }
    }
    
}


bool solve(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (result[x + i][y + j] == 1 && paper[i][j] == 1) {
                return false;
            }
        }
    }

    // 붙이기 가능 -> result 갱신
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (paper[i][j] == 1) {
                result[x + i][y + j] = 1;
            }
        }
    }
    return true;
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int K = 0; K < k; K++) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> paper[i][j];
            }
        }

        for (int rot = 0; rot < 4; rot++) {
            bool canSolve = false;
            for (int i = 0; i < n - r + 1; i++) {
                for (int j = 0; j < m - c + 1; j++) {
                    if (solve(i, j)) {
                        canSolve = true;
                        break;
                    }
                }
                if (canSolve) {
                    break;
                }
            }
            if (canSolve) {
                break;
            }
            rotate();
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (result[i][j] == 1) {
                cnt++;
            }
        }
    }
    cout << cnt;
}