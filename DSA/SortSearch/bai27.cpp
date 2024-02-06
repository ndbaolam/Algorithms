#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	set<int> b;
	for(int &i : a)	
	{
		cin >> i;
		b.insert(i);
	}

	for(int i=0;i<n;i++)
	{
		auto it = b.upper_bound(a[i]);
		if(it!=b.end())
			cout << *it << " ";
		else
			cout << "_ ";
	}
}