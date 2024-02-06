#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int mod = 1e9+7;
ll powMod(ll a, ll b)
{
    if(b==0) return 1;
    ll x = powMod(a,b/2);
    if(b%2==0) return (x*x)%mod;
    return (a%mod)*(x*x%mod)%mod;
}

int main()
{
    ll a, b; cin >> a >> b;
    cout << powMod(a%mod,b);
}