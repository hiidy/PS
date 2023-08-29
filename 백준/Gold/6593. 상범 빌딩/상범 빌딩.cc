#include <bits/stdc++.h>
using namespace std;

int h, n, m;
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
char board[32][32][32];
int dist[32][32][32];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        cin >> h >> n >> m;
        if (h == 0 && n == 0 && m == 0)
            return 0;

        queue<tuple<int, int, int>> q;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    char input;
                    cin >> input;
                    board[i][j][k] = input;
                    if (input == 'S') {
                        q.push({i, j, k});
                    }
                    if (input == '#') {
                        dist[i][j][k] = -1;
                    } else {
                        dist[i][j][k] = 0;
                    }
                }
            }
        }
        while (!q.empty()) {
            int x, y, z;
            tie(z, x, y) = q.front();
            q.pop();
            for (int i = 0; i < 6; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h)
                    continue;
                if (dist[nz][nx][ny] != 0)
                    continue;
                q.push({nz, nx, ny});
                dist[nz][nx][ny] = dist[z][x][y] + 1;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (board[i][j][k] == 'E') {
                        if (dist[i][j][k] == 0) {
                            cout << "Trapped!"
                                 << "\n";
                        } else {
                            cout << "Escaped in " << dist[i][j][k]
                                 << " minute(s)."
                                 << "\n";
                        }
                    }
                }
            }
        }
    }
}
