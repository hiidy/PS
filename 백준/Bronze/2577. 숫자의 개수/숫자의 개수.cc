#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B, C;
    int array[10] = {};
    cin >> A >> B >> C;
    int sum = A * B * C;

    while (sum > 0) {
        array[sum % 10]++;
        sum /= 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << array[i] << '\n';
    }
}