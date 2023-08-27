#include<bits/stdc++.h>
using namespace std;

bool vis[52][52];
int arr[52][52];
int t, n, m, k;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > q;

void bfs(int x, int y) {
    vis[x][y] = 1;
    q.push({x, y});
    while(!q.empty()) {
        int a, b;
        tie(a, b) = q.front();q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny] == 1 || arr[nx][ny] == 0) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        int ans = 0;
        cin >> m >> n >> k;
        for(int i = 0; i < k; i ++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && arr[i][j] == 1) {
                    bfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
        for(int i = 0; i < n; i++) {
            fill(arr[i], arr[i]+m, 0);
            fill(vis[i], vis[i]+m, 0);
        }

    }
}
