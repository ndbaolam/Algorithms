#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, x; cin >> n >> x;
    int a[n];
    for(int &i : a)
        cin >> i;
    map<ll,int> mp;
    ll sum=0,cnt=0;
    for(int i : a)
    {
        sum+=i;
        if(sum==x)
            cnt++;
        if(mp.count(sum-x))
            cnt+=mp[sum-x];
        mp[sum]++;
    }
    cout << cnt;
    return 0;
}