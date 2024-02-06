#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 1000000

ll a[MAX];
int n;

void nhap()
{
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
}
void solve()
{
	ll F[n];
	for(int i=0;i<n;i++)
	{
		if(i==0) F[0]=a[0];
		else
		{
			F[i]=F[i-1]+a[i];
		}
	}
	for(ll i : F)
		cout << i << " ";
}
int main()
{
	nhap();
	solve();
}