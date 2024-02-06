#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	multimap<int,int> mp;

	for(int i=1;i<=n;i++)
	{
		int a, b; cin >> a >> b;
		mp.insert({b,a});
	}
	int tmp = mp.begin()->first;
	int cnt = 1;

	auto it = mp.begin();
	++it;

	for(auto i = it; i!=mp.end(); ++i)
	{
		if(i->second>=tmp)
		{
			cnt++;
			tmp=i->first;
		}
	}
	cout << cnt;
	return 0;
}