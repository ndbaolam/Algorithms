#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1e6+5;
ll f[MAX];
ll mod = 1e9+7;
ll inv[MAX];

ll powMod(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans%mod;
}

void solve()
{
    f[0]=1;
    for(int i=1;i<MAX;i++)
        f[i]=(1ll*f[i-1]*i)%mod;

    inv[MAX-1] = powMod(f[MAX-1],mod-2);
    for(int i=MAX-2;i>=0;i--)
        inv[i]=(1ll*inv[i+1]*(i+1)) % mod;
}

ll C(ll n, ll k)
{
    return ((f[n]*inv[n-k])%mod * inv[k])%mod;
}

void runcase()
{
    map<char,int> mp;
    string s; cin >> s;
    for(char c : s)
        mp[c]++;

    ll ans=f[s.size()];
    for(auto [x,k] : mp)
    {
        ans = (ans*inv[k]) % mod;
    }
    cout << ans << endl;
}
int main()
{
    solve();
    runcase();
    return 0;
}