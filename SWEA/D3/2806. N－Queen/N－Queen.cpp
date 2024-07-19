#include<iostream>

using namespace std;

int n;
int cnt;
bool usedCol[30];
bool diagonal1[30];
bool diagonal2[30];

void backtracking(int row) {

    if (row == n) {
        cnt++;
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (usedCol[col] || diagonal1[row + col] || diagonal2[row - col + n]) {
            continue;
        }
        usedCol[col] = 1;
        diagonal1[row + col] = 1;
        diagonal2[row - col + n] = 1;
        backtracking(row + 1);
        usedCol[col] = 0;
        diagonal1[row + col] = 0;
        diagonal2[row - col + n] = 0;
        
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {   
        cin >> n;
        cnt = 0;
        backtracking(0);
		cout << '#' << test_case << ' ' << cnt << '\n';

    }
    return 0;
}