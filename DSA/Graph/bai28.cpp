#include<bits/stdc++.h>
//#include "E:\Code\Cprograming\debug.h"
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 1005;
const ll mod = 1e9 + 7;

vector<int> a[N];
bool visited[N];
int n, m, cnt;

void inp()
{
	cin >> n >> m;
	REP(i,1,m)
	{
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

int max_sz, vertex;
vector<int> res;

void DFS(int v)
{
	//++cnt;
	int tmp = a[v].size();
	if(tmp > max_sz || tmp == max_sz && v < vertex)
	{
		vertex = v;
		max_sz = tmp;
	}
	//debug(v, res);
	visited[v] = true;
	for(int x : a[v])
		if(!visited[x])
			DFS(x);
}

int main()
{
	inp();
	REP(i,1,n)
	{
		if(a[i].empty())
			res.push_back(i);
		else
		{
			sort(all(a[i]));
			if(!visited[i])
			{
				max_sz = 0;
				vertex = i;
				DFS(i);
				res.push_back(vertex);
			}
		}		
	}
	sort(all(res));
	for(int x : res)
		cout << x << ' ';
}