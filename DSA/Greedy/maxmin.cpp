#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n, k; cin >> n >> k;
	ll a[n];
	for(ll &i : a) cin >> i;	
	sort(a,a+n);
	ll ans=1e9+1;
	for(int i=0;i<n-k;i++)
		ans=min(a[i+k-1]-a[i],ans);
	if(n==k) cout << a[n-1]-a[0];
	else cout << ans;
}