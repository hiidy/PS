#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string memory;
        char memoryCount = '0';
        int result = 0;
        cin >> memory;

        for (char c : memory) {
            if (c != memoryCount) {
                result++;
                memoryCount = c;
            }
        }

       cout << '#' << test_case << " " << result << '\n';
    }
    return 0;
}