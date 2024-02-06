#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, q; cin >> n >> q;
	int a[n];
	for(int &i : a)
		cin >> i;

	int D[n];
	for(int i=0;i<n;i++)
	{
		if(i==0) D[i]=a[i];
		else
		{
			D[i]=a[i]-a[i-1];
		}
	}

	while(q--)
	{
		int l, r, k;
		cin >> l >> r >> k;

		D[l]+=k;
		D[r+1]-=k;
	}
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=D[i];
		cout << sum << " ";
	}
	
}