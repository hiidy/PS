#include<bits/stdc++.h>
using namespace std;

// 1이동불가 0이동가능
//시작칸 끝칸 포함해서 세기
// 벽을 한 개 까지 부술 수 있다.

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string board[1002];
int dist[1002][1002][2];
int n, m;

void bfs() {
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    queue<tuple<int, int, int> > q;
    q.push({0, 0, 0});
    while(!q.empty()) {
        int x, y, b;
        tie(x, y, b) = q.front();q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >=n || ny>=m) continue;
            if(board[nx][ny] == '0' && dist[nx][ny][b] == 0) {
                dist[nx][ny][b] = dist[x][y][b] + 1;
                q.push({nx, ny, b});
            }
            if(!b && board[nx][ny] == '1' && dist[nx][ny][b] == 0) {
                dist[nx][ny][1] = dist[x][y][b] + 1;
                q.push({nx, ny, 1});
            }
            
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    bfs();
    if(dist[n-1][m-1][1] == 0 && dist[n-1][m-1][0]==0) {
        cout << -1;
    } else if(dist[n-1][m-1][1] != 0 && dist[n-1][m-1][0]!=0) {
        cout << min(dist[n-1][m-1][1], dist[n-1][m-1][0]);
    } else {
        cout << max(dist[n-1][m-1][1], dist[n-1][m-1][0]);
    }
}