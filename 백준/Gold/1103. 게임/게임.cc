#include<bits/stdc++.h>
using namespace std;
#define X first;
#define Y second;
int graph[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dp[51][51];
bool visited[51][51];
int cnt = 0;
int n, m, ans;
int dfs(int, int);



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'H') {
                graph[i][j] = -1;
            } else {
                graph[i][j] = s[j] - '0';
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    ans = dfs(0, 0);
    cout << ans;

    
}

int dfs(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m || graph[x][y] == -1) {
        return 0;
    }
    if(visited[x][y] == 1) {
        cout << -1;
        exit(0);
    }
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    
    
    dp[x][y] = 0;
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i] * graph[x][y];
        int ny = y + dy[i] * graph[x][y];
        dp[x][y] = max(dfs(nx, ny)+1, dp[x][y]);
    }
    visited[x][y] = 0;
    return dp[x][y];
}