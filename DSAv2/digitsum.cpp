#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int to_digit(int i)
{
	int sum = 0;
	while(i)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

ll solve(ll a, ll b)
{
	ll sum = 0;
	for(ll i = a; i <= b; i++)
	{
		sum += to_digit(i);
	}
	return sum;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		ll a, b; cin >> a >> b;
		cout << solve(a,b) << endl;
	}
}