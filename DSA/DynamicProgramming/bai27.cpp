#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int max_digit(int n)
{
	int ans = 0;
	while(n)
	{
		ans = max(ans, n % 10);
		n /= 10;
	}
	return ans;
}

int main()
{
	int n; cin >> n;
	vector<ll> f(n+1);
	//f[i] so buoc bien doi de i = 0
	for(int i = 2; i <= n; i++)
		f[i] = f[i - max_digit(i)] + 1;
	cout << f[n];
}