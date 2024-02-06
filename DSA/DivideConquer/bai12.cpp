#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

struct Matrix{
	ll a[2][2];

	friend Matrix operator * (Matrix x, Matrix y)
	{
		Matrix res;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				res.a[i][j] = 0;
				for(int k=0;k<2;k++)
				{
					res.a[i][j] += x.a[i][k] * y.a[k][j];
					res.a[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

Matrix binpow(Matrix a, ll n)
{
	if(n==1) return a;
	Matrix x = binpow(a,n/2);
	if(n&1) return x * x * a;
	else return x * x;
}

int main()
{
	Matrix X;
	X.a[0][0] = 1;
	X.a[1][0] = 1;
	X.a[0][1] = 1;
	X.a[1][1] = 0;

	ll n; cin >> n;

	Matrix res = binpow(X,n);
	cout << res.a[0][1] << endl;
}