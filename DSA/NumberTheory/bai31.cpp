#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
	if(b==0) return a;
	else return(b,a%b);
}

ll phi(ll n)
{
	ll ans = n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans -= ans/i;
			while(n%i==0) n/=i;
		}
	}
	if(n!=1)
		ans-= ans/n;
	return ans;
}

int main()
{
	ll n; cin >> n;
	cout << phi(n);
}