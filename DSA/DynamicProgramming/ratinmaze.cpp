#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
ll f[1005][1005];
int main()
{
	int n; cin >> n;
	char a[n+1][n+1];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(a[i][j] != '*')
			{
				if(i == 1 && j == 1) f[i][j] = 1;
				else 
					f[i][j] = f[i-1][j] + f[i][j-1];
			}
			f[i][j] %= mod;
		}
	}
	cout << f[n][n];
}