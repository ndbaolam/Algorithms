#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	priority_queue<int> pq(a,a+n);
	ll sum=0;
	ll mod = 1e9+7;
	while(pq.size()>1)
	{
		ll x = pq.top(); pq.pop();
		ll y = pq.top(); pq.pop();
		ll total = x+y; total%=mod;
		sum = (sum%mod + total)%mod;
		pq.push(total);
	}
	cout << sum;
}