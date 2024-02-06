#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

ll solve(int k, string s)
{
	map<char,int> mp;
	for(char c : s) mp[c]++;
	priority_queue<int> a;
	for(auto i : mp) a.push(i.second);

	while(k--)
	{
		int tmp = a.top(); a.pop();
		a.push(--tmp);
	}

	if(a.empty()) return 0;

	ll sum=0;
	while(!a.empty())
	{
		int x = a.top(); a.pop();
		sum+=1ll*x*x;
	}
	return sum;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int k; cin >> k;
		string s; cin >> s;
		if(k>=s.size()) cout << 0 << endl;
		else cout << solve(k,s) << endl;
	}
}