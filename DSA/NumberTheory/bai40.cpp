#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = (int)1e6+5;
ll m[maxn][maxn];
ll mod = 1e9+7;

ll C(int k, int n)
{
	if(k==0||k==n) return 1;
	else
	{
		if(m[k][n]==0)
		{
			m[k][n] = C(k-1,n-1) + C(k,n-1);
			m[k][n]%=mod;
		}
		return m[k][n];
	}
}

int main()
{
	int n, k; cin >> n >> k;
	cout << C(k-1,n+k-1);
	return 0;
}