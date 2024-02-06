#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = unsigned long long;

const ll mod = 1e9 + 7;

ll binpow(ll a, ll b)
{
	if(b == 0) return 1;
	ll x = binpow(a, b/2);
	x = (x * x) % mod;
	if(b & 1) x = (x * (a % mod)) % mod;
	return x;
}

int main()
{
	

	ll a, b; cin >> a >> b;
	cout << binpow(a, b) << endl;
}
