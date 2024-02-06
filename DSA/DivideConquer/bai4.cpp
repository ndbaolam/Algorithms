#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int solve(ll n, ll k)
{
	if(k == 1ll*pow(2,n-1)) return n;
	else if(k < 1ll*pow(2,n-1)) return solve(n-1,k);
	else return solve(n-1,k - 1ll*pow(2,n-1));
}

int main()
{
	ll n, k; cin >> n >> k;
	cout << solve(n,k);
}