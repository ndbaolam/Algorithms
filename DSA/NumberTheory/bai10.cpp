#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t; cin >> t;
    ll sum  = 1;
    ll mod = 1e9+7;
    while(t--)
    {
        ll p, e; cin >> p >> e;
        ++e;

        sum*=e;
        sum%=mod;
    }
    cout << sum;
}