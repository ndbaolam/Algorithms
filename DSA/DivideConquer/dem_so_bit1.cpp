#include <bits/stdc++.h>
using namespace std;
long long F[107];

void init() {
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= 100; ++i)
        F[i] = F[i - 1] * 2 + 1;
}

int f(long long n, long long i, int k) {
    if (i == F[k - 1] + 1)
        return n % 2;
    if (i <= F[k - 1])
        return f(n / 2, i, k - 1);
    else
        return f(n / 2, i - F[k - 1] - 1, k - 1);
}

int main() {
    init();
    long long n, l, r;
    cin >> n >> l >> r;
    int cnt = 0;
    int k = 0;
    while (F[k] < n)
        ++k;
    for (long long i = l; i <= r; ++i) 
        cnt += f(n, i, k);
    cout << cnt;
    return 0;
}