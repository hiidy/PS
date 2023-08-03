#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1002][1002];
int mx;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            arr[i][j] = input[j] - '0';
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] != 0) {
                arr[i][j] =
                    min({arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1]}) + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mx = max(mx, arr[i][j]);
        }
    }
    cout << pow(mx, 2);
}
