#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int s, n; cin >> s >> n;
	vector<int> a(n+1);
	ll f[n+1][s+1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	//f[i][j] khoi luong bo cua i con bo dau tien va j kg 

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= s; j++)
		{
			if(i == 0 || j == 0)
				f[i][j] = 0;
			else
			{
				if(j >= a[i]) 
					f[i][j] = max(f[i-1][j], f[i-1][j - a[i]] + a[i]);
				else f[i][j] = f[i-1][j];
			}
		}
	}
	cout << f[n][s];
}