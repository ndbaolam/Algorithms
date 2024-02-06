#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	sort(a,a+n);
	ll sum=0;
	ll mod = 1e9+7;
	for(int i=0;i<n;i++)
	{
		sum = (sum%mod + (a[i]%mod)*i%mod)%mod;
	}
	cout << sum;
}