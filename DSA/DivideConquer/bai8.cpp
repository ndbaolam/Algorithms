#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m), c;
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;

	int i = 0, j = 0;
	while(i < n && j < m)
	{
		if(a[i] < b[j]) c.push_back(a[i++]);
		else c.push_back(b[j++]);
	}
	while(i < n) c.push_back(a[i++]);
	while(j < m) c.push_back(b[j++]);

	cout << c[--k];
}