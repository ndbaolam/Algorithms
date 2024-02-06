#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, k; cin >> n >> k;
	int a[n];
	for(int &i : a) cin >> i;
	sort(a,a+n);
	int l=0;
	ll ans=0;
	for(int r=0;r<n;r++)
	{
		ans=a[r]-a[l];
		while(ans>k)
		{
			++l;
			ans=a[r]-a[l];
			if(ans==k)
			{
				cout << 1; return 0;
			}
		}
	}
	cout << -1;
	return 0;
}