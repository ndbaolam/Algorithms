#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	string s; cin >> s;
	int n = s.size(), ans = 0;
	int f[n][n];
	//f[i][j] palindrome start at i and end at j position
	for(int i = 0; i < n; i++) f[i][i] = 1;
	for(int i = 0; i < n - 1; i++)
		if(s[i] == s[i+1])
			f[i][i+1] = 2;

	for(int k = 3; k <= n; k++)
	{
		for(int i = 0; i < n - k + 1; i++)
		{
			int j = i + k - 1;
			if(f[i+1][j-1] && s[i] == s[j])
				f[i][j] = f[i+1][j-1] + 2;
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			ans = max(ans, f[i][j]);
	cout << ans;
}