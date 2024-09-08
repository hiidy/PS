#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int arr[201][201];
bool vist[201];
int answer = 0;

void bfs(int start, int n, vector<vector<int>> computers) {
    if (vist[start] == true) {
        return;
    }
    answer++;
    queue<int> q;
    q.push(start);
    vist[start] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (computers[cur][i] == 0) {
                continue;
            }
            if (vist[i] == 1) {
                continue;
            }
            q.push(i);
            vist[i] = true;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) {
        bfs(i, n, computers);
    }
    return answer;
}