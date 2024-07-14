#include<iostream>

using namespace std;

int n;
int value[1000002];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

		cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> value[i];
        }
        int max_value = value[n - 1];
        long long sum_value = 0;
        
        for (int i = n - 2; i >= 0; i--) {
            if (value[i] <= max_value){
                sum_value += (max_value - value[i]);
            } else if (value[i] > max_value){
            	max_value = value[i];
            }
        }
        cout << "#" << test_case << ' ' << sum_value << '\n';
        
        

	}
	return 0;
}