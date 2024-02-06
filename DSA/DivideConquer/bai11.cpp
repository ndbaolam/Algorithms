#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(int &x : v) cin >> x;
	if(binary_search(all(v),k)) cout << "YES";
	else cout << "NO";
}