#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int graph[502][502] = {};
bool visited[502][502];
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int mx = 0;
int cnt = 0;
queue<pair<int, int>> Q;


int bfs(int x, int y) {
    visited[x][y] = 1;
    Q.push({x, y});
    int area = 1;
    while(!Q.empty()) {
        pair<int, int> current = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = current.X + dx[i];
            int ny = current.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if (visited[nx][ny] == 0 && graph[nx][ny] == 1) {
                visited[nx][ny] = 1;
                Q.push({nx, ny});
                area ++;
            }
         }
    }
    return area;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0 && graph[i][j] == 1){
                mx = max(mx, bfs(i, j));
                cnt ++;
            }

        }
    }

    cout << cnt << '\n' << mx;

}