#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, k; cin >> n >> k;
	int a[n];
	for(int &i : a)
		cin >> i;
	sort(a,a+n,greater<int>());
	ll sum=0;
	for(int i=0;i<=k;i++)
		sum+=a[i];
	if(k+1<n)
	{
		for(int i=k+1;i<n;i++)
			sum-=a[i];
	}
	
	cout << sum;
	return 0;
}