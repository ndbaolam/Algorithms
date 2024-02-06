#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int n, s, sum, cnt;
int a[55];
vector<string> res;

void solve()
{
	for(int i=0;i<(1<<(n));i++)
	{
		int sum=a[0];
		string tmp=to_string(a[0]);
		for(int j=1;j<n;j++)
		{
			if(i&(1<<j)) 
			{
				sum+=a[j];
				tmp+="+"+to_string(a[j]);
			}
			else 
			{
				sum-=a[j];
				tmp+="-"+to_string(a[j]);
			}
		}
		if(sum==s) 
		{
			++cnt;
			res.push_back(tmp);
		}
	}
}

int main()
{
	cin >> n >> s;
	for(int i=0;i<n;i++)
		cin >> a[i];
	solve();
	cout << cnt << endl;
	for(auto x : res)
		cout << x << endl;
}