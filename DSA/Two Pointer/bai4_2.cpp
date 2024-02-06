#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, k; cin >> n >> k;
	int a[n+5];
	for(int i=1;i<=n;i++)
		cin >> a[i];

	int l=1,r=1;
	ll sum=0;
	int ans=1e6;
	
	for(r;r<=n;r++)
	{
		sum+=a[r];
		while(sum>=k)
		{
			ans=min(ans,r-l+1);
			sum-=a[l];
			++l;
		}
	}

	cout << ans << endl;
}