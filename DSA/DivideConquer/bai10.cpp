#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int& x : a) cin >> x;
	int l = 0, r = n-1;
	while(l<=r)
	{
		int m = (r+l)/2;
		if(a[m] && !a[m-1])
		{
			cout << m;
			return 0;
		}
		else if(a[m])
			r = m-1;
		else l = m+1;
	}
	cout << 0;
}