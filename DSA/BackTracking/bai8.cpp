#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair <int,int>;

const int INF = 1e9;
const int MAX = 1e9+5;
const ll mod = 1e9+7;

int n, k, final;
int a[25], x[25];
bool endn = false;

void sinh()
{
	int i=n;
	while(i>=1 && x[i]==k-1)
	{
		x[i]=0;
		--i;
	}
	if(i==0) final=1;
	else
		++x[i];
}

void solve()
{
	while(!final)
	{
		map<int,int> mp;
		for(int i=1;i<=n;i++)
			mp[x[i]]+=a[i];
		int tmp = mp.begin()->second;
		bool check = true;
		for(auto [i,j] : mp)
		{
			if(mp.size()!=k || j!=tmp) 
			{
				check = false;
				break;
			}
		}
		if(check)
		{
			endn = true;
			cout << 1;
			return;
		}
		sinh();
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	solve();
	if(!endn) cout << 0;
}