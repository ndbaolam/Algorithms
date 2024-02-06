#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, k; cin >> n >> k;
	int a[n];
	for(int &i : a)
		cin >> i;
	sort(a,a+n);
	int cnt=0;

	for(int i=1;i<n;i++)
	{
		if(a[i]-a[i-1] > k)
		{
			cnt++;
			if(i==n-1) cnt++;
		}
	}
	cout << cnt;
	return 0;
}