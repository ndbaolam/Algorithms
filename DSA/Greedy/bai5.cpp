#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

void solve(int a[], int n)
{
	for(int i=0;i<=n/2;i++)
	{
		if(a[i]>a[n-i-1])
			swap(a[i],a[n-i-1]);
	}
}

bool check(int a[], int n)
{
	for(int i=0;i<n-1;i++)
		if(a[i+1]<a[i]) return false;
	return true;
}

int main()
{
	int n; cin >> n;
	if(n&1)
	{
		int a[n];
		for(int &i : a)
			 cin >> i;
		solve(a, n);

		if(check(a,n)) cout << "YES";
		else cout << "NO";
	}
	else cout << "NO";
}