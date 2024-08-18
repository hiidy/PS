#include <iostream>
#include <algorithm>
#include <map>
#include <deque>
#define X first
#define Y second

using namespace std;

int n, k, l;
int board[102][102]; //0 없음 1 뱀 
bool apple[102][102];
int dx[4] = {0, 1, 0, -1}; //동 남 서 북
int dy[4] = {1, 0, -1, 0};
deque<pair<int,int> > snake;
map<int, char> m;

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        apple[x][y] = true;
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int k;
        char v;
        cin >> k >> v;
        m[k] = v;
    }
    int time = 0;
    int dir = 0; // 동쪽부터 시작하기 때문에 0으로 시작
    snake.push_back({1, 1});
    while (true) {
        time++;
        pair<int, int> top = snake.back();
        int nx = top.X + dx[dir];
        int ny = top.Y + dy[dir];
        if (nx < 1 || ny < 1 || nx >= n + 1 || ny >=n + 1) {
            break;
        }
        if (find(snake.begin(), snake.end(), make_pair(nx, ny)) != snake.end()) {
            break;
        }
        snake.push_back({nx, ny});
        if (apple[nx][ny]) {
            apple[nx][ny] = false;
        } else {
            snake.pop_front();
        }
        if (m[time]) {
            if (m[time] == 'L') {
                dir = (dir + 3) % 4;
            } else if (m[time] == 'D') {
                dir = (dir + 1) % 4;
            }
        }
    }
    cout << time;

}