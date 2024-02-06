#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll f[20][140][2];

ll digit_sum(vector<int>& a, int idx, int sum, int tight)
{
	if(idx == -1) return sum;
	if(f[idx][sum][tight] != -1 and tight != 1)
		return f[idx][sum][tight];
	ll res = 0;
	int k = (tight) ? a[idx] : 9;
	REP(i,0,k)
	{
		int new_tight = (a[idx] == i) ? tight : 0;
		res += digit_sum(a, idx-1, sum+i, new_tight);
	}
	if(!tight)
		f[idx][sum][tight] = res;
	return res;
}

vector<int> get_digit(ll a)
{
	vector<int> res;
	while(a)
	{
		res.push_back(a%10);
		a /= 10;
	}
	return res;
}

int main()
{
	memset(f, -1, sizeof(f));
	int T; cin >> T;
	while(T--)
	{
		ll x, y; cin >> x >> y;
		vector<int> a = get_digit(x-1);
		vector<int> b = get_digit(y);
		cout << digit_sum(b,b.size()-1,0,1) - digit_sum(a,a.size()-1,0,1) << endl;
	}
}