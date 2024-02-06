#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n; cin >> n;
	ll a[n]; 
	for(ll &x : a) cin >> x;
	ll ans = 0, sum = 0;
	for(ll x : a)
	{
		sum += x;
		if(sum < 0) sum = 0;
		ans = max(ans,sum);
	}
	cout << ans;
}