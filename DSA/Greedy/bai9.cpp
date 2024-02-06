#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n; cin >>n;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(int i=0;i<n;i++)
	{
		ll val; cin >> val;
		pq.push(val);
	}
	ll mod=1e9+7;
	ll res=0;
	while(pq.size()>1)
	{
		ll x = pq.top(); pq.pop();
		ll y = pq.top(); pq.pop();
		res+=x+y;
		res%=mod;
		pq.push(x+y);
	}
	cout << res;
}