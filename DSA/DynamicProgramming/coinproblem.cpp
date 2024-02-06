#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n, s; cin >> n >> s;
	vector<int> a(n+1), f(s+1, INT_MAX);
	for(int i = 1; i <= n ; i++) cin >> a[i];

	for(int i = 1; i <= s; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			f[a[j]] = 1;
			if(i - a[j] >= 0 && f[i-a[j]] != INT_MAX)
			{
				f[i] = min(f[i] , f[i - a[j]] + 1);
			}
		}
	}	
	if(f[s] != INT_MAX) cout << f[s];
	else cout << -1;
}