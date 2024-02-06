#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, m; cin >> n >> m;
	multiset<int> ms;
	//u gia ve
	//v gia toi da
	for(int i=0;i<n;i++)
	{
		int x; cin >> x;
		ms.insert(x);
	}	

	for(int i=0;i<m;i++)
	{
		int x; cin >> x;
		auto it = ms.upper_bound(x);
		if(it == ms.begin())
		{
			cout << -1 << endl;
		}
		else
		{
			--it;
			cout << *it << endl;
			ms.erase(it);
		}
	}
}