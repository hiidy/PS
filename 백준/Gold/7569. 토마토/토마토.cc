#include<bits/stdc++.h>
using namespace std;

int n, m, h;
int board[103][103][103];
int dist[103][103][103];
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    queue<tuple<int, int, int>> q;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                int input;
                cin >> input;
                board[i][j][k] = input;
                if(input == 1) {
                    q.push({i, j, k});
                } else if(input == 0) {
                    dist[i][j][k] = -1;
                }
            }
        }
    }

    while(!q.empty()) {
        int x, y, z;
        tie(z, x, y) = q.front();q.pop();
        for(int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx< 0 || ny < 0 || nz <0) continue;
            if(nx >= n || ny >= m || nz >= h) continue;
            if(dist[nz][nx][ny] != -1 || board[nz][nx][ny] == -1) continue;
            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }

    int ans = 0;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(dist[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }

    cout << ans;
}

