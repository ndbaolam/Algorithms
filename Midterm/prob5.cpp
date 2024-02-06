#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

ll s1[1005], s2[1005], s0[1005], a[1005];
ll mod = 1e9 + 7;

int main()
{
	faster();
	int n; cin >> n;

	s0[0] = s1[0] = s2[0] = 1;
	REP(i, 1, n)
	{
		s2[i] = (s0[i - 1] + s1[i - 1] + s2[i - 1]) % mod;
		s1[i] = (s2[i - 1] + s0[i - 1]) % mod;
		s0[i] = (s2[i - 1] + s1[i - 1]) % mod;
	}
	cout << (s0[n - 1] + s1[n - 1] + s2[n - 1]) % mod;
}