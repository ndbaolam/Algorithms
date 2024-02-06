#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n, m; cin >> n >> m;
	long long a[n], b[m];
	for(long long &i : a)
		cin >> i;
	for(long long &i : b)
		cin >> i;
	int i = 0, j =0;
	while(i<n&&j<n)
	{
		if(a[i]>=b[j])
		{
			cout << b[j] << " ";
			j++;
		}
		else if(b[j]>=a[i])
		{
			cout << a[i] << " ";
			i++;
		}
	}
	while(i<n)
	{
		cout << a[i] << " ";
		i++;
	}
	while(j<n)
	{
		cout << b[j] << " ";
		j++;
	}
	
	return 0;
}