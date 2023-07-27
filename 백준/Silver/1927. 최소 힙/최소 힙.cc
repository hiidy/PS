#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> heapq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        int input;
        cin >> input;
        if(input == 0) {
            if(!heapq.empty()) {
                cout << heapq.top() << "\n";
                heapq.pop();
            } else {
                cout << 0 << "\n";
            }
        } else {
            heapq.push(input);
        }
    }
}