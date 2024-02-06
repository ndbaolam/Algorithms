#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll binpow(ll a, ll b, ll m)
{
    a%=m;
    ll res =1;
    while(b>0)
    {
        if(b&1)
            res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}

int main()
{
    ll a; cin >> a;
    ll m = 1e9+7;
    cout << binpow(a,m-2,m);
    return 0;
}