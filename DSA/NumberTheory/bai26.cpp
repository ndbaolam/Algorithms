#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(ll x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return x>=2;
}

int main()
{
	ll n; cin >> n;
	for(int p=2;p<=32;p++)
	{
		if(isPrime(p) && isPrime((1ll << p)-1))
		{
			if(n== ((1ll << p)-1) * (1ll << (p-1)))
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}