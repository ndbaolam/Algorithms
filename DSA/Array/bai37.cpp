#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   int n, k;
   cin >> n >> k;
   int a[n];
   for(int &i : a)
           cin >> i;
    ll sum=0;
    int ans =-1;
    map<ll,int> mp;
    for(int i=0;i<n;i++)
    {
    	sum+=a[i];
    	sum%=k;
    	if(sum==0)
    		ans = i+1;
    	if(mp.count(sum))
    		ans=max(ans,i-mp[sum]+1);
    	if(!mp.count(sum))
    		mp[sum]=i;
    }
    cout << ans;
}