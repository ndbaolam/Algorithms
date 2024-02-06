#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	int a[n];
	multiset<int> chan, le;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i]%2!=0) le.insert(a[i]);
		else chan.insert(a[i]);
	}
	for(auto i = le.rbegin();i!=le.rend();i++)
		cout << *i << " ";
	for(int i : chan) cout << i << " ";
}