#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9+7;

int solve(ll n, ll k)
{
    ll s=1;
    ll sum=0;
    while(k)
    {
        int d=k%2;
        k/=2;
        if(d)
        {
            sum+=s*d;
            sum%=mod;
        }
        s*=n;
        s%=mod;
    }
    return sum;
}

int main()
{
    ll n, k; cin >> n >> k;   
    cout << solve(n,k);
    return 0;
}