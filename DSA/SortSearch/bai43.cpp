#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int &i : a)
        cin >> i;
    map<ll,int> mp;
    ll sum=0,cnt=0;
    for(int i : a)
    {
        sum+=i;
        sum=(sum % n+n)%n; // sum luon la so duong
        if(sum==0)
            cnt++;
        if(mp.count(sum))
            cnt+=mp[sum];
        mp[sum]++;
    }
    cout << cnt;
    return 0;
}