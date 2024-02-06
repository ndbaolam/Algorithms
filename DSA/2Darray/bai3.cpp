#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n,m; cin >> n >> m;
	int a[n][m];

	int maxi=0, mini=(int)1e9;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j];
			maxi=max(a[i][j],maxi);
			mini=min(a[i][j],mini);
		}
	}
	cout << mini << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==mini)
				cout << i+1 << " " << j+1 << endl;
		}
	}
	cout << maxi << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==maxi)
				cout << i+1 << " " << j+1 << endl;
		}
	}
}