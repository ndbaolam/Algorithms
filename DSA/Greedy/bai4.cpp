#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int &i : a)
		cin >> i;
	sort(a,a+n);
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		if(k<=n/2)
		{		
			if(i<k) ans-=a[i];
			else ans+=a[i];
		}
		else
		{
			if(i<n-k) ans-=a[i];
			else ans+=a[i];
		}
	}
	cout << ans;
}