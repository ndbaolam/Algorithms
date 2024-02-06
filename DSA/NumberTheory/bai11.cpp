#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  	ll l, r;
    cin >> l >> r;
    int x = sqrt(l);
    if (1ll * x * x != l) ++x;
    for (int i = x; i <= sqrt(r); ++i)
        cout << (i * i) << " ";   
}