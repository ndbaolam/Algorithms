#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, s; cin >> n >> s;
	int a[n];
	for(int &i : a) cin >> i;

	int cnt=0;
	ll sum=0;
	ll ans = 0;

	int l=0;
	for(int r=0;r<n;r++)
	{
		sum+=a[r];
		while(sum>s)
		{
			sum-=a[l];
			++l;
		}
		ans+=r-l+1;
	}
	cout << ans << endl;
}