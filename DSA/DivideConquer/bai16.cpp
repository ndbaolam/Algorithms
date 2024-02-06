#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

struct Matrix{
	ll a[12][12];
	int n;

	friend Matrix operator * (Matrix x, Matrix y)
	{
		Matrix res;
		res.n = x.n;
		for(int i = 0; i < x.n; i++)
		{
			for(int j = 0; j < x.n; j++)
			{
				res.a[i][j] = 0;
				for(int k = 0; k < x.n; k++)
				{
					res.a[i][j] += x.a[i][k] * y.a[j][k];
					res.a[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

Matrix binpow(Matrix a, ll k)
{
    if(k==1) return a;
    Matrix x = binpow(a,k/2);
    if(k&1) return x * x * a;
    else return x * x;
}

int main()
{
	Matrix x; ll k;
	cin >> x.n >> k;
	for(int i=0;i<x.n;i++)
		for(int j=0;j<x.n;j++)
			cin >> x.a[i][j];

	Matrix res = binpow(x,k);

	ll sum = 0;
	for(int i=0;i<x.n;i++)
	{
		sum += res.a[i][x.n-1];
		sum %= mod;
	}
	cout << sum << endl;
}