#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int ngto(int n)
{
	for(int i=2;i<sqrt(n);i++)
		if(n%i==0) return 0;
	return n>1;
}
bool check(int a[], int n)
{
	for(int i=0;i<n;i++)
		if(a[i]!=a[n-1-i]) return false;
	return true;
}
int main()
{
	int n; cin >> n;
	int a[n], b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	int maxpos=0, minpos=0, cnt=0;
	for(int i =0;i<n;i++)
	{
		if(a[i]>a[maxpos])
			maxpos=i;
		if(a[i]<=a[minpos])
			minpos=i;
		if(ngto(a[i])) ++cnt;
	}
	cout << a[maxpos] << " " << maxpos << endl;
	cout << a[minpos] << " " << minpos << endl;
	cout << cnt << endl;
	cout << max(1ll * b[n-1]*b[n-2], 1ll* b[0]*b[1]) << endl;
	if(check(a,n)) cout << "YES\n";
	else cout << "NO\n";
	long long res = 1;
	int mod = 1e9+7;
	for(int x:a)
	{
		res*=x;
		res%=mod;
	}
	cout << res;
}