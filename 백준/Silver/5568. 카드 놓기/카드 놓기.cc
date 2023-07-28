#include<bits/stdc++.h>
using namespace std;

vector<string> v;
bool visited[11];
set<string> ans;
string perm[11];
int n, k;

void dfs(int depth) {
    if(depth == k) {
        string perm_string;
        for(auto s : perm) {
            perm_string+=s;
        }
        ans.insert(perm_string);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(visited[i] == true) {
            continue;
        }
        visited[i] = true;
        perm[depth] = v[i];
        dfs(depth + 1);
        visited[i] = false;

    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> k;
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        v.push_back(input);
    }
    dfs(0);
    cout << ans.size();


}