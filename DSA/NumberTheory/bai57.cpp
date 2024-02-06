#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
const int MAX = 1e9+30;
ll mod = 1e9+7;

ll a,b,c,m;

ll powMod()
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return ans%m;
}

ll inv(ll i) {
  return i <= 1 ? i : m - 1ll*(m/i) * inv(m % i) % m;
}

int main()
{
    cin >> a >> b >> c >> m;
    cout <<  powMod()*inv(c) %m << endl;
}