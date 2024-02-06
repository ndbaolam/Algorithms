#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n,x; cin >> n >> x;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	auto it1 = lower_bound(a,a+n,x);
	if(*it1==x)
		cout << it1-a << endl;
	else cout << -1 << endl;

	auto it2 = upper_bound(a,a+n,x);
	--it2;
	if(*it2==x)
		cout << it2-a-1 << endl;
	else cout << -1 << endl;

	if(it1!=a+n)
		cout << it1-a << endl;
	else cout << -1 << endl;

	++it2;
	if(it2!=a+n)
		cout << it2-a << endl;
	else cout << -1 << endl;

	cout << it2-it1 << endl;
}