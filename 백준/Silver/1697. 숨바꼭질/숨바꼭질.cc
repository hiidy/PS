#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dist[100001];
int n, k;
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(dist, dist + 100001 , -1);
    q.push(n);
    dist[n] = 0;
    while(dist[k] == -1) {
        auto cur = q.front();
        q.pop();
        for(int nx : {cur+1, cur-1, 2*cur}) {
            if(nx == k) {
                dist[nx] = dist[cur] + 1;
                break;
            }
            if(nx >= 100001 || nx < 0) {
                continue;
            }
            if(dist[nx] != -1) {
                continue;
            }
            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }
    cout << dist[k];
}
