#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

int t;

void insert_num(string &tmp, deque<int> &dq) {
    string str_num = "";
    if(tmp.size() == 2) return;
    for (int i = 1; i < tmp.size(); i++) {
        if(isdigit(tmp[i])) {
            str_num += tmp[i];
        } else {
            int num = stoi(str_num);
            dq.push_back(num);
            str_num = "";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        deque<int> dq;
        string input;
        int n;
        string tmp;
        bool error = 0;
        bool rev = 0;
        cin >> input;
        cin >> n;
        cin >> tmp;
        insert_num(tmp, dq);
        for (auto c : input) {
            if (c == 'R') {
                rev = !rev; // 0이면 pop_front 1이면 pop_back
            } else {
                if (dq.empty()) {
                    error = true;
                    break;
                } else {
                    if (rev) {
                        dq.pop_back();
                    } else {
                        dq.pop_front();
                    }
                }
            }
        }
        if (error) {
            cout << "error"
                 << "\n";
        } else {
            if (rev) {
                reverse(dq.begin(), dq.end());
            }
            cout << '[';
            for (int i = 0; i < dq.size(); i++) {
                if (i == dq.size() - 1) {
                    cout << dq[i];
                } else {
                    cout << dq[i] << ',';
                }
            }
            cout << ']' << "\n";
        }
    }
}