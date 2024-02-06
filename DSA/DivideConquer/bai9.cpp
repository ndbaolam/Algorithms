#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n; cin >> n;
	vector<int> a(n), b(n-1);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	b.push_back(a[n-1]);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			cout << a[i];
			return 0;
		}
	}
	cout << a[n-1];
}