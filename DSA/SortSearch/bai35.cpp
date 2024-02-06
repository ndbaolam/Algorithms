#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, k; cin >> n >> k;
	int a[n]; 
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	int i=0, j=n-1, cnt=0;
	while(j>i)
	{
		if(a[i]+a[j] <= k)
		{
			cnt++;
			i++;
			j--;
		}
		else
		{
			j--;
			cnt++;
		}
	}
	if(j == i)
		cnt++;
	cout << cnt;
}