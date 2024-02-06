#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll fibo[93];

void init()
{
	fibo[1] = 1;
	for(int i=2;i<=92;i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
}

char solve(ll n, ll k)
{
	if(n==1) return 'A';
	if(n==2) return 'B';

	if(k <= fibo[n-2]) return solve(n-2, k);
	else return solve(n-1, k-fibo[n-2]);
}

int main()
{
	ll n, k; cin >> n >> k;
	init();
	cout << solve(n,k);
}