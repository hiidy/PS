#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char** argv)
{
    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; ++test_case)
    {   
        int n;
        cin >> n;
        
        unordered_map<int, int> frequency;
        int max_frequency = 0;
        int mode = 0;

        for (int i = 0; i < 1000; i++) {
            int score;
            cin >> score;
            frequency[score]++;

            if (frequency[score] > max_frequency || 
               (frequency[score] == max_frequency && score > mode)) {
                max_frequency = frequency[score];
                mode = score;
            }
        }

        cout << '#' << test_case << ' ' << mode << '\n';
    }
    return 0;
}