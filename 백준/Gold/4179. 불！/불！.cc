#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m;
int dx[4] = {1, -1, 0, 0,};
int dy[4] = {0, 0, 1, -1};
int dist1[1002][1002]; //지훈
int dist2[1002][1002]; // 불
string graph[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> graph[i];
        fill(dist1[i], dist1[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
    }
    queue<pair<int, int> > q1;
    queue<pair<int, int> > q2;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(graph[i][j] == 'J') {
                q1.push({i,j});
                dist1[i][j] = 0;
            }
            if(graph[i][j] == 'F') {
                q2.push({i,j});
                dist2[i][j] = 0;
            }
        }
    }

    //불
    while(!q2.empty()) {
        auto cur = q2.front();
        q2.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if(dist2[nx][ny] >= 0 || graph[nx][ny] == '#') {
                continue;
            }
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            q2.push({nx, ny});
        }
    }

    while(!q1.empty()) {
        auto cur = q1.front();
        q1.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                cout << dist1[cur.X][cur.Y] + 1;
                return 0;
            }
            if(dist1[nx][ny] >= 0 || graph[nx][ny] == '#') {
                continue;
            }
            if(dist2[nx][ny] != -1 &&dist2[nx][ny] <= dist1[cur.X][cur.Y] + 1){
                continue;
            }
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            q1.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}
 