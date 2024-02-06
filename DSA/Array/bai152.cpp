#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int &i : a)
		cin >> i;
	sort(a,a+n);
	
	
	int mini = 1e9;
	int cnt=1;
	for(int i=1;i<n-1;i++)
	{
		int m = min(a[i]-a[i-1],a[i+1]-a[i]);
		if(m<mini) mini=m;
		if(mini==m) cnt++;
	}
	
	int x = a[1]-a[0];
	int y = a[n-1]-a[n-2];
	if(mini > x)
	{
		mini=x;
		cnt=1;
	}
	else if(mini>y)
	{
		mini=y;
		cnt=1;
	}
	else if(mini==x) cnt++;
	else if(mini==y) cnt++;

	cout << mini << " " << cnt;
}