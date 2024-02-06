#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	string x, y, z;
	cin >> x >> y >> z;
	int n = x.size(), m = y.size(), p = z.size();

	int f[n + 1][m + 1][p + 1];
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			for(int k = 0; k <= p; k++)
			{
				if(i == 0 || j == 0 || k == 0)
					f[i][j][k] = 0;
				else
				{
					if(x[i - 1] == y[j - 1] && x[i - 1] == z[k - 1])
						f[i][j][k] = f[i - 1][j - 1][k - 1] + 1;
					else f[i][j][k] = max(f[i - 1][j][k], max(f[i][j - 1][k], f[i][j][k - 1]));
				}
			}
		}
	}
	cout << f[n][m][p];
}