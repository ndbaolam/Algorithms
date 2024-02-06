#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair <int,int>;

int n, S;
int a[25], X[105];
vector<vector<int>> res;
bool check = false;

void nhap()
{
	cin >> n >> S;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
}

void Try(int i, int sum, int pos)
{
	for(int j=pos;j<=n;j++)
	{
		X[i] = a[j];
		sum += X[i];
		if(sum==S)
		{
			check = true;
			vector<int> tmp(X+1,X+i+1);
			res.push_back(tmp);
		}
		else if(sum<S) Try(i+1,sum,j);
		sum-=X[i];
	}
}

void solve()
{
	if(!check)
	{
		cout << -1;
		return;
	}
	
	cout << res.size() << endl;
	for(auto i : res)
	{
		cout << "{";
		for(int j=0;j<(int)i.size();j++)
		{
			if(j==(int)i.size()-1) cout << i[j];
			else cout << i[j] << " ";
		}
		cout << "}" << endl;
	}
}

int main()
{
	nhap();
	Try(1,0,1);
	solve();
}