#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int f[n], a[n];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        f[i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = 1ll * max(f[i], f[j] + 1);
    cout << *max_element(f+1,f+n+1);
}