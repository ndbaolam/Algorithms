#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	vector<int> v;
	int x; while(cin >> x) v.push_back(x);
	int ans = 0, sum = 0;
	for(int i=0;i<v.size();i++)
	{
		sum += v[i];
		if(sum < 0) sum=0;
		ans = max(ans, sum);
	}
	cout << ans;
}