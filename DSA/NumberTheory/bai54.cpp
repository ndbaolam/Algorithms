#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1e6+5;

ll fac[MAX];
ll inv[MAX];
ll mod = 1e9+7;

ll binpow(ll a, ll b)
{
    a%=mod;
    ll res=1;
    while(b>0)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}

void prepare()
{
    fac[0]=1;
    for(int i=1;i<MAX;i++)
        fac[i]=fac[i-1]*i%mod;

    inv[MAX-1]=binpow(fac[MAX-1],mod-2);
    for(int i = MAX-2;i>=0;i--)
        inv[i] = inv[i+1]*(i+1)%mod;
}

int main()
{
    prepare();
    ll n; cin >> n;
    ll ans = fac[n];

    for(int i=0;i<4;i++)
    {
        int x; cin >> x;
        ans = ans*inv[x] % mod;
    }
    cout << ans;
    return 0;
}