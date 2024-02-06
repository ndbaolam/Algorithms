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

int n, k, a[20], x[20], cnt;
vector<vector<int>> res;
void in()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
}

void ql(int i, int pos, int sum)
{
	for(int j=pos;j<=n;j++)
	{
		if(sum+a[j] <= k)
		{
			x[i]=a[j];
			if(sum+a[j]==k)
			{
				vector<int> tmp(x+1,x+i+1);
				res.push_back(tmp);
			}
			else ql(i+1,j+1,sum+x[i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	in();
	sort(a+1,a+n+1);
	ql(1,1,0);

	for(auto i : res)
	{
		cout << "[";
		for(int j : i)
		{
			if(j!=*i.rbegin())
				cout << j << ' ';
			else cout << j;
		}
		cout << "]" << endl;
	}
}