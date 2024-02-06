#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll a[105][105];
int main()
{
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n ; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
    {
        for(int j = 1;  j <= m; j++)
        {
            a[i][j] += max(a[i-1][j],a[i][j-1]);
        }
    }
    cout << a[n][m];
}