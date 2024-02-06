#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, k; cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	ll ans=0;
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		auto it = upper_bound(a+i+1,a+n,k-a[i]);
		ans += a+n-it;
	}
	cout << ans << endl;
}