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
    int ans=-1, start=-1;
    ll sum=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==0)
        {
            ans=i+1;
            start=0;
        }
        if(mp.count(sum))
        {
            if(ans < i-mp[sum])
            {
                ans=i-mp[sum];
                start=mp[sum]+1;
            }
        }
        else mp[sum]=i;
    }
    if(ans==-1)
        cout << "NOT FOUND";
    else
    {
        for(int i=0;i<ans;i++)
            cout << a[start+i] << " ";
    }
}