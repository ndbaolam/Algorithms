#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

ll s0[1005], s1[1005];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	int n, a, b; cin >> n >> a >> b;
	ll mod = 1e9 + 7;

	s1[0] = s0[0] = 1;
	REP(i, 1, n)
	{
		s0[i] = s1[i - 1] % mod;
		REP(k, a, b)
		{
			int j = i - k;
			if(j >= 0) s1[i] += s0[j];
			s1[i] %= mod;
		}
	}
	cout << (s0[n] + s1[n]) % mod << endl;
}

/*
	- chuỗi 1 liên tiếp >= a <= b
	- Giữa các chuỗi 1 có đúng 1 bit 0
	=> S0[i] la so xau nhi phan do dai i, bit i = 0
	=> S1[i] la so xau nhi phan do dai i, bit i = 1

	S0[i] = S1[i-1]
	S1[i] = sigma(a <= i - j <= b) S0[j]

*/