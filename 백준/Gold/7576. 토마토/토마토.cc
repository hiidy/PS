#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
queue <pair<int, int>> Q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int graph[1001][1001];
int dist[1001][1001];
int ans;

void bfs(void) {
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if (dist[nx][ny] < 0) {
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                Q.push({i, j});
            }
            if (graph[i][j] == 0) {
                dist[i][j] = -1;
            }
        }
    }

    bfs();
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans;
}
