#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        while (!dq.empty() && dq.back().first >= input) {
            dq.pop_back();
        }

        dq.push_back({input, i});

        if (dq.front().second < i - l + 1) {
            dq.pop_front();
        }
        cout << dq.front().first << " ";
    }
}