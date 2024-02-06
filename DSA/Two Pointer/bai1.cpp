#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, m; cin >> n >> m;
	int a[n], b[m];
	for(int &i : a) cin >> i;
	for(int &i : b) cin >> i;

	int i=0,j=0;
	while(i<n && j < m)
	{
		if(a[i]<=b[j])
		{
			cout << a[i] << " ";
			i++;
		}
		else 
		{
			cout << b[j] << " ";
			j++;
		}
	}

	while(i<n) 
	{
		cout << a[i] << " ";
		i++;
	}
	while(j<m)
	{
		cout << b[j] << " ";
		j++;
	}
}