#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int a[], int n, int k, double m)
{
	ll cnt=0;
	for(int i=0;i<n;i++)
	{
		cnt+=(int)(a[i]/m);
	}
	return cnt >= k;
}

int main()
{
	int n, k; cin >> n >> k;
	int a[n];
	for(int &i : a) cin >> i;
	double l=0, r=9e18;
	double ans=-1;
	for(int i=0;i<200;i++)
	{
		double m =(r+l)/2;
		if(check(a,n,k,m))
		{
			ans=m;
			l=m;
		}
		else r=m;
	}
	cout << fixed << setprecision(6) << ans;
	return 0;
}