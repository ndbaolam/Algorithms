#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	 int n; cin >> n;
	int a[n];
	for(int &i : a)
		cin >> i;

	ll incr = 0;
	for(int i=1;i<n;i++)
	{
		if(a[i]<=a[i-1])
		{
			incr+=a[i-1]+1-a[i];
			a[i]=a[i-1]+1;
		}
	}
	cout << incr;
}