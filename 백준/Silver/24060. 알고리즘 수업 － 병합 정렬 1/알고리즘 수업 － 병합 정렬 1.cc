#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[500002];
int tmp[400000];
int cnt = 0;

void merge(int A[], int p, int q, int r, int k) {
    int i = p;
    int j = q + 1;
    int t = 1;
    while (i <= q && j <= r) {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }
    while (i <= q)
        tmp[t++] = A[i++];
    while (j <= r)
        tmp[t++] = A[j++];
    i = p;
    t = 1;
    while (i <= r) {
        cnt++;
        A[i++] = tmp[t++];
        if (k == cnt) {
            cout << tmp[t - 1];
            break;
        }
    }
}

void merge_sort(int A[], int p, int r, int k) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q, k);
        merge_sort(A, q + 1, r, k);
        merge(A, p, q, r, k);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    merge_sort(arr, 0, n - 1, k);
    if (cnt < k)
        cout << -1;
}
