#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

ll binpow(ll a, ll b)
{
    if(b==0) return 1;
    ll x = binpow(a,b/2);
    if(b&1) return x*x*a;
    else return x*x;
}

int main()
{
    int n; cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    sort(a,a+n,greater<int>());
    ll ans=0;
    for(int i=0;i<n;i++)
        ans+=1ll*binpow(2,i)*a[i];
    cout << ans;
}