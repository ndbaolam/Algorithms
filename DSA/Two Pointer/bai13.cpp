#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n, k; cin >> n >> k;
	int a[n];
	for(int &i :a)
		cin >> i;

	ll sum=0;
	ll ans=0;
	int l=0;
	int idx;
	for(int r=0;r<n;r++)
	{
		sum+=a[r];
		if(r==l+k-1)
		{
			if(sum>ans)
			{
				ans=sum;
				idx=r;
			}
			sum-=a[l];
			++l;
		}
	}
	cout << ans << endl;
	for(int i=l;i<=idx;i++)
		cout << a[i] << " ";
}