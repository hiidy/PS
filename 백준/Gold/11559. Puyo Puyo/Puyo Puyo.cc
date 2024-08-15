#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ROW = 12;
int COL = 6;
char board[12][6];

void down() {
    char tmpBoard[12][6];
    memset(tmpBoard, '.', sizeof(tmpBoard));

    for (int i = 0; i < COL; i++) {
        int idx = ROW - 1;
        for (int j = ROW - 1; j >= 0; j--) {
            if (board[j][i] == '.') {
                continue;
            }
            if (tmpBoard[idx][i] == '.') {
                tmpBoard[idx][i] = board[j][i];
                idx--;
            } 
        }
    }

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = tmpBoard[i][j];
        }
    }
}

void remove(vector<pair<int, int> >& result) {
    for (pair<int, int> i : result) {
        int x = i.first;
        int y = i.second;
        board[x][y] = '.';
    }
}

void bfs(vector<pair<int, int>>& result, int x, int y, char color, vector<vector<bool>>& visited) {
    queue<pair<int, int> > q;
    q.push({x, y});
    visited[x][y] = true;
    result.push_back({x, y});

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= ROW || ny >= COL) {
                continue;
            }
            if (visited[nx][ny] == true || board[nx][ny] != color) {
                continue;
            }
            q.push({nx, ny});
            visited[nx][ny] = true;
            result.push_back({nx, ny});
        }
    }
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 12; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < 6; j++) {
            board[i][j] = input[j];
        }
    }
    bool chain = false;
    int answer = 0;
    while (true) {
        vector<vector<bool> > visited(ROW, vector<bool>(COL, false));
        chain = false;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                vector<pair<int, int>> result;
                if (board[i][j] == '.' || visited[i][j] == true) {
                    continue;
                }
                bfs(result, i, j, board[i][j], visited);
                if (result.size() >= 4) {
                    remove(result);
                    chain = true;
                }
            }
        }

        if (chain) {
            answer++;
            down();
        } else {
            break;
        }
    }
    cout << answer;
    
}