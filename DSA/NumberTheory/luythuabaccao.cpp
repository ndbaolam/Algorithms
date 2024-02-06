#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll powMod(ll a, ll b, ll M)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%M;
        a = (a*a)%M;
        b >>= 1;
    }
    return ans%M;
}
int main()
{
    int t; cin >> t;
    ll M = 1e9+7;
    while(t--)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        ll x = powMod(b,c,M-1);
        cout << powMod(a,x,M) << endl;
    }
    return 0;
}