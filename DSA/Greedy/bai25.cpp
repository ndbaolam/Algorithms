#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    ll sum=0, cnt=0;
    sort(a,a+n);
    for(int i : a)
    {
        if(sum<=i)
        {
            sum+=1ll*i;
            ++cnt;
        }
    }
    cout << cnt;
}