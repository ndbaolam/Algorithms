#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int INF = 1e9;
const int MAX = 1e9+5;
ll mod = 1e9+7;

int n, s, w[20], v[20];
vector<ll> weight, val;

void preapre()
{
	for(int i=0;i<(1<<n);i++)
	{
		ll sum=0, value=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				sum+=w[j];
				value+=v[j];
			}
		}
		weight.push_back(sum);
		val.push_back(value);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for(int i=0;i<n;i++)
		cin >> w[i];
	for(int i=0;i<n;i++)
		cin >> v[i];
	preapre();
	ll ans=0;
	for(int i=0;i<weight.size();i++)
	{
		if(weight[i]<=s)
			ans=max(ans,val[i]);
	}
	cout << ans;
}