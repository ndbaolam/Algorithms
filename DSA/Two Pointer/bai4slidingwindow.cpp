#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n, k; cin >> n >> k;
	int a[n];
	for(int &i :a)
		cin >> i;

	for(int i=0;i<n-k+1;i++)
		cout << *min_element(a+i,a+i+k-1) << " " << *max_element(a+i,a+i+k-1) << endl;

}