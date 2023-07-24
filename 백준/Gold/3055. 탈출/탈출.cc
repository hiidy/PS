#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int dist1[52][52]; // 물
int dist2[52][52]; // 고슴도치
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string graph[52];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> graph[i];
        fill(dist1[i], dist1[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
    }

    queue<pair<int, int> > q1; //물
    queue<pair<int, int> > q2; // 고슴도치

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == '*') {
                q1.push({i, j});
                dist1[i][j] = 0;
            }

            if(graph[i][j] == 'S') {
                q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }

    //물
    while(!q1.empty()) {
        auto cur = q1.front();
        q1.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if(graph[nx][ny] == 'X' || graph[nx][ny] == 'D') {
                continue;
            }
            if(dist1[nx][ny] >= 0) {
                continue;
            }
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            q1.push({nx, ny});
        }
    }

    while(!q2.empty()) {
        auto cur = q2.front();
        q2.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if(graph[nx][ny] == 'D') {
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                cout << dist2[nx][ny];
                return 0;
            }
            if(graph[nx][ny] == 'X' || dist2[nx][ny] >= 0) {
                continue;
            }
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) {
                continue;
            }
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            q2.push({nx, ny});
        }
    }

    cout << "KAKTUS";

}
