#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int graph[101][101] = {};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> Q;
int cnt = 0;

int bfs(int x, int y) {
    Q.push({x, y});
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if (graph[nx][ny] == 0) {
                continue;
            }
            if (graph[nx][ny] == 1) {
                graph[nx][ny] = graph[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
                
            }
        }
    }
    return graph[n-1][m-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            graph[i][j] = row[j] - '0';
        }
    }

    cout << bfs(0, 0);

}