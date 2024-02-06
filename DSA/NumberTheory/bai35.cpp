#include<bits/stdc++.h>
using namespace std;
using ll = long long;

long double lcm (ll x, ll y)
{
	return x / __gcd(x,y) * y;
}

int main()
{
	ll a,b; cin >> a >> b;
	cout << __gcd(a,b) << " " << lcm(a,b);
}