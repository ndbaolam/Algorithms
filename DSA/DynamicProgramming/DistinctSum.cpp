#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	for(int &x : a) cin >> x;
	int S = accumulate(all(a),0);
	
	bool f[n+1][S+1];
	memset(f,false,sizeof(f));
	for(int i = 1; i <= n; i++)
	{
		f[i][a[i-1]] = true;
		for(int j = 0; j <= S; j++)
		{
			if(j == 0) f[i][j] = true;
			else
			{
				if(f[i-1][j] == true)
				{
					f[i][j] = true;
					f[i][j + a[i-1]] = true;
				}
			}
		}
	}
	for(int j = 0; j <= S; j++)
		if(f[n][j] == true)
			cout << j << ' ';
}