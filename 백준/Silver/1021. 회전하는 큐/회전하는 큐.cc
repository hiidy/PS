#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    deque<int> dq;
    int cnt = 0;

    for(int i = 1; i <=n; i++) {
        dq.push_back(i);
    }
    
    for(int i = 0; i < m; i++) {
        int input;
        cin >> input;
        int idx1 = find(dq.begin(), dq.end(), input) - dq.begin();
        int idx2 = dq.end() - find(dq.begin(), dq.end(), input) + 1;

        if (idx1 >= idx2) {
            while(dq.front() != input) {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        } else {
            while(dq.front() != input) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
        dq.pop_front();
    }
    cout << cnt;  
}