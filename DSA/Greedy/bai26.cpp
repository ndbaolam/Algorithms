#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

bool cmp(int a, int b)
{
    if(abs(a)!=abs(b))
        return abs(a) < abs(b);
    else return a < b;
}

int main()
{
    int n; cin >> n;
    int a[n];
    for(int &i : a) cin >> i;

    sort(a,a+n,cmp);
    int ans=1e9;
    for(int i=0;i<n-1;i++)
        ans = min(ans,abs(a[i+1]-a[i]));
    cout << ans;
}