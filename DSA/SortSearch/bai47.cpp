#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int a[], int n, ll k, ll m)
{
    ll time=0;
    for(int i=0;i<n;i++)
    {
        time+=m/a[i];
    }
    return time>=k;
}

int main()
{
    int n; cin >> n;
    ll k; cin >> k;
    int a[n];
    for(int &i : a) cin >> i;
    ll l = 0;
    ll r = 1ll*(*min_element(a,a+n)*k);
    ll ans=-1;
    while(l<=r)
    {
        ll m = (r+l)/2;
        if(check(a,n,k,m))
        {
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    cout << ans;
    return 0;
}