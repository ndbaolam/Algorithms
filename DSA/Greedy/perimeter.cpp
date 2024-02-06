#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	sort(a, a+n);
	for(int i=n-1;i>1;i--)
	{
		if(a[i]-a[i-1] < a[i-2])
		{
			cout << a[i-2] << ' ' << a[i-1] << ' ' << a[i];
			return 0;
		}
	}
	cout << -1;
}