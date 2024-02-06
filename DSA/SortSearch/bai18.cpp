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
		auto it1 = lower_bound(a+i+1,a+n,k-a[i]);
		--it1;
		int pos = it1 - a;
		ans+= pos - i;
	}
	cout << ans << endl;
}