#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > minq;
priority_queue<int> maxq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        int input;
        cin >> input;
        if(maxq.empty()) {
            maxq.push(input);
            cout << maxq.top() << "\n";
            continue;
        }
        if(maxq.size() > minq.size()) {
            if(maxq.top() > input) {
                maxq.push(input);
                minq.push(maxq.top());
                maxq.pop();
                cout << maxq.top() << "\n";
                continue;
            } else {
                minq.push(input);
                cout << maxq.top() << "\n";
                continue;
            }
        }
        if(maxq.size() == minq.size()) {
            if(input > minq.top()) {
                minq.push(input);
                maxq.push(minq.top());
                minq.pop();
                cout << maxq.top() << "\n";
                continue;
            }
                maxq.push(input);
                cout << maxq.top() << "\n";
                continue;
        }
    }
}