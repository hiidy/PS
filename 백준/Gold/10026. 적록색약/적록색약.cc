#include <bits/stdc++.h>
using namespace std;

int n, rg, not_rg;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
// 1 적록 2 평범
string arr[102];
bool vist[102][102];
queue<pair<int, int>> q;

void bfs(int x, int y) {
    q.push({x, y});
    vist[x][y] = 1;
    while (!q.empty()) {
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (vist[nx][ny] == 1 || arr[nx][ny] != arr[x][y])
                continue;
            q.push({nx, ny});
            vist[nx][ny] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vist[i][j] == 0) {
                bfs(i, j);
                not_rg++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 'R') {
                arr[i][j] = 'G';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        fill(vist[i], vist[i] + n, 0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vist[i][j] == 0) {
                bfs(i, j);
                rg++;
            }
        }
    }

    cout << not_rg << " " << rg;
}
