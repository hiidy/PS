#include<iostream>
#include <cmath>

using namespace std;

int n;
int arr[52][52];

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        for (int i = 0; i < n; i++) {
            string input;
            cin >> input;
            for (int j = 0; j < n; j++) {
                arr[i][j] = input[j] - '0';
            }
        }
        int result = 0;
        int mid = (n - 1) / 2;

        for (int i = 0; i < mid; i++) {
            for (int j = mid - i; j <= mid + i; j++) {
                result += arr[i][j];
                result += arr[n - i - 1][j];
            }
        }

        for (int i = 0; i < n; i++) {
            result += arr[mid][i];
        }

        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;
}