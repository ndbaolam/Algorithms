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

int n, a[10][10], used[10][10], ans;
vector<string> res;
string tmp="";

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
string m[4] = {"R","D","L","U"};

void loang(int i, int j)
{
	if(i==n && j==n)
	{
		ans=1;
		res.push_back(tmp);
	}
	else
	{
		for(int k=0;k<4;k++)
		{
			int i1 = i+dx[k];
			int j1 = j+dy[k];
			if(a[i1][j1] && !used[i1][j1]) 
			{
				tmp.append(m[k]);
				used[i1][j1]=1;
				loang(i1,j1);
			}
		}
	}
	tmp.pop_back();
	used[i][j]=0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> a[i][j];

	loang(1,1);

	if(!ans) cout << -1;
	else
	{
		sort(all(res));
		for(auto i : res)
		{
			bool check = true;
			for(int j=0;j<i.length()-1;j++)
			{
				if(i[j]=='R' && i[j+1]=='L')
					check=false;
				if(i[j]=='D' && i[j+1]=='U')
					check=false;
			}
			if(check)
				cout << i << endl;
		}
	}
}