#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
const int MAX = 1e9+5;
ll mod = 1e9+7;

int n, a[20], final;
vector<vector<int>> res;

int main()
{
	cin >> n;
	set<int> s;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int x; cin >> x;
		if(!s.count(x))
			v.push_back(x);
		s.insert(x);
	}

	sort(all(v),greater<int>());
	do{
		for(int i : v)
			cout << i << ' ';
		cout << endl;
	}while(prev_permutation(all(v)));
}