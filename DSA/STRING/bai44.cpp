#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main()
{
	string n; cin >> n;
	ll m; cin >> m;
	ll r=0;

	for(char i : n)
	{
		r=r*10+ (i-'0');
		r%=m;
	}
	cout << gcd(r,m);
}

