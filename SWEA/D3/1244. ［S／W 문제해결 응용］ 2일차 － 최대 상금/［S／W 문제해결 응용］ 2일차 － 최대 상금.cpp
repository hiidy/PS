#include<iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

string swapNum(string num, int i, int j) {
    swap(num[i], num[j]);
    return num;
}

int findMaxNum(string num, int change_count) {
    if (change_count == 0 || num.length() == 1) {
        return stoi(num);
    }

    string key = num + to_string(change_count);

    if (m.find(key) != m.end()) {
        return m[key];
    }


    int maxNum = -1;

    for (int i = 0; i < num.length() - 1; i++) {
        for (int j = i + 1; j < num.length(); j++) {
            string swappedNum = swapNum(num, i, j);
            int resultNum = findMaxNum(swappedNum, change_count - 1);
            maxNum = max(maxNum, resultNum);
        }
    }

    m[key] = maxNum;

    return maxNum;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string num;
        int change_count;
        cin >> num >> change_count;
        m.clear();
        int result = findMaxNum(num, change_count);

        cout << '#' << test_case << ' ' << result << '\n';
	
    }
    return 0;
}