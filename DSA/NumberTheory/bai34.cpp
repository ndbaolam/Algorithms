#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
ll lcm(ll a, ll b)
{
	return a/gcd(a,b)*b;
}

ll solve(int n, int x, int y, int z)
{
	ll tmp = lcm(lcm(x,y),z);
	ll m = (ll)pow(10,n-1);
	ll res = (m+tmp-1)/tmp*tmp;
	if(res<(ll)pow(10,n))
		return res;
	else return -1;
}
int main()
{
	int x,y,z,n;
	cin >> x >> y >> z >> n;
	cout << solve(n,x,y,z);
	return 0;
}