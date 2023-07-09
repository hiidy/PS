#include<bits/stdc++.h>

using namespace std;
int arr[1001];
bool visited[1001];

void dfs(int start) {
    visited[start] = 1;
    int next = arr[start];
    if (!visited[next]) {
        dfs(next);
    }
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++ ) {
        int n;
        int ans = 0;
        cin >> n;

        fill(visited, visited + 1001, 0);
        fill(arr, arr + 1001, 0);

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
                ans++;
            }
        }
        cout << ans << "\n";

    }
	return 0;
}