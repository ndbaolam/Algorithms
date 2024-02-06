#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, d; cin >> n >>d;
    ll a[n];
    for(ll &i : a)
        cin >> i;

    ll ans=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]<=a[i-1])
        {
            ll add =a[i-1]-a[i] +1;
            ll cnt = (add+d-1)/d*d;
            a[i]+=cnt;
            ans+=cnt/d;
        }
    }
    cout << ans;
}