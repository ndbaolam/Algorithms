#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];

	int x = *max_element(a,a+n);
	int y = *min_element(a,a+n);
	cout << x-y+1-n;
}