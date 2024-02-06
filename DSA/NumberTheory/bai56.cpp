#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a, b, n; 

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

ll cal(int x, int y)
{
    return ((fac[n]*inv[x])%mod*inv[y])%mod;
}

bool isGood(int m)
{
    while(m)
    {
        int x=m%10;
        if(x!=a && x!=b)
            return false;
        m/=10;
    }
    return true;
}

int main()
{   
    prepare();
    cin >> a >> b >> n;
    if(a<b) swap(a,b);
    ll ans = 0;
    for(int sum=n;sum<=9*n;sum++)
    {
        if(!isGood(sum)) continue;
            int x = (sum-n*b)/(a-b);
            int y = n-x;
            if(a*x + b*y == sum && x>=0 && y>=0)
            {
                ans+=cal(x,y);
                ans%=mod;
            }
    }
    cout << ans;
    return 0;
}