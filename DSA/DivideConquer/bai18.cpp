#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
unordered_map<ll,string> mp;

string solve(ll n)
{
	if(n == 2) return mp[2];
    if(n == 3) return mp[3];

    if(!mp.count(n))
    	mp[n] = solve(n/2) + to_string(n%2) + solve(n/2);
    return mp[n];
}

int main()
{
	ll n, l, r; cin >> n >> l >> r;
	mp[2] = "101";
	mp[3] = "111";
	string ans = solve(n);
	ll cnt = 0;
	for(int i = l; i <= r; i++)
		if(ans[i] == '1') ++cnt;
	cout << cnt << endl;
}

//8-15: 15
//4 - 7: 7