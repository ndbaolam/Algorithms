#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, s; cin >> n >> s;
	int a[n];
	for(int &i : a) cin >> i;

	ll sum=0;
	ll ans = 0;

	int l=0;
	for(int r=0;r<n;r++)
	{
		sum+=a[r];
		while(sum>=s)
		{
			ans+=n-r;
			sum-=a[l];
			++l;
		}
	}
	cout << ans << endl;
}