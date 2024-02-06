#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 1000000

ll a[MAX];
int n;
int Q;

void nhap()
{
	cin >> n >> Q;
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
	while(Q--)
	{
		int l, r;
		cin >> l >> r;
		if(l==0) cout << F[r] << endl;
		else
			cout << F[r]-F[l-1] << endl;
	}
}
int main()
{
	nhap();
	solve();
}