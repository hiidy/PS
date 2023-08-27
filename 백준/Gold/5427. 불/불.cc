#include <bits/stdc++.h>
using namespace std;

int t, n, m;
;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int board[1002][1002];
int dist_fire[1002][1002];
int dist_me[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> m >> n;
        queue<pair<int, int>> q_fire;
        queue<pair<int, int>> q_me;

        for (int i = 0; i < n; i++) {
            fill(dist_fire[i], dist_fire[i] + m, 0);
            fill(dist_me[i], dist_me[i] + m, 0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char input;
                cin >> input;
                if (input == '@') {
                    q_me.push({i, j});
                    dist_me[i][j] = 1;
                    board[i][j] = 1;
                } else if (input == '.') {
                    board[i][j] = 1;
                } else if (input == '#') {
                    board[i][j] = 0;
                } else if (input == '*') {
                    q_fire.push({i, j});
                    dist_fire[i][j] = 1;
                    board[i][j] = 1;
                }
            }
        }

        // 불 먼저
        while (!q_fire.empty()) {
            int x, y;
            tie(x, y) = q_fire.front();
            q_fire.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (dist_fire[nx][ny] != 0 || board[nx][ny] == 0)
                    continue;
                q_fire.push({nx, ny});
                dist_fire[nx][ny] = dist_fire[x][y] + 1;
            }
        }
        bool can_escape = 0;

        while (!q_me.empty()) {
            int x, y;
            tie(x, y) = q_me.front();
            q_me.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    cout << dist_me[x][y] << "\n";
                    can_escape = true;
                    break;
                }
                if (dist_me[nx][ny] != 0 || board[nx][ny] == 0)
                    continue;
                if (dist_fire[nx][ny] != 0 &&
                    dist_fire[nx][ny] <= dist_me[x][y] + 1)
                    continue;
                q_me.push({nx, ny});
                dist_me[nx][ny] = dist_me[x][y] + 1;
            }
            if (can_escape) {
                break;
            }
        }
        if (!can_escape) {
            cout << "IMPOSSIBLE"
                 << "\n";
        }
    }
}