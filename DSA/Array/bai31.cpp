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
    	if(sum==k)
    		ans=min(ans,i+1);
    	if()
    }
    cout << ans;
}