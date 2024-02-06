#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

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
	ll n; cin >> n;
	cout << powMod(2,n-1,mod);
}