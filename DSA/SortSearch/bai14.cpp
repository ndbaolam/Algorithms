#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int &i : a) cin >> i;

	sort(a,a+n,greater<int>());
	ll ans = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]-i > 0)
			ans+=a[i]-i;
	}
	cout << ans;
	return 0; 
}
