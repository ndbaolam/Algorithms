#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int a[105][105];
int main()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1;  j <= n; j++)
		{
			a[i][j] += max(max(a[i-1][j], a[i-1][j-1]), a[i-1][j+1]);
		}
	}
	int ans = 0;
	for(int j = 1; j <= n; j++)
		ans = max(ans, a[n][j]);
	cout << ans;
}