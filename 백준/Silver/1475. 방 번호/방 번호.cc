#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int array[10] = {};
    int max = 0;

    while(N > 0) {
        if (N%10 == 6) {
            array[9]++;
        }
        else {
            array[N%10]++;
        }
        N /= 10;
    }

    if(array[9] % 2 == 0) {
        array[9] /= 2;
    }
    else if(array[9] %  2 != 0) {
        array[9] = array[9] / 2 + 1;
    }

    for(int i = 0; i < 10; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    cout << max;
}