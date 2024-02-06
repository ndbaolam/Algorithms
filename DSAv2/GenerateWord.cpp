#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
char a[50][50];
string tmp = "";
int visited[50][50];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int n, m, ok;
string s;

bool check(int i, int j)
{
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

void back(int i, int j)
{
	if(ok) return;
	if(tmp == s)
	{
		ok = 1;
		return;
	}
	REP(k,0,3)
	{
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(check(i1,j1) and !visited[i1][j1])
		{
			tmp += a[i1][j1];
			visited[i1][j1] = 1;
			if(tmp == s)
				ok = 1;
			else if(s.find(tmp) != string::npos)
				back(i1,j1);
			tmp.pop_back();
			visited[i1][j1] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	REP(i,1,n)
		REP(j,1,m)
			cin >> a[i][j];
	cin >> s;
	memset(visited, false, sizeof(visited));

	REP(i,1,n)
	{
		REP(j,1,m)
		{
			if(a[i][j] == s[0])
			{
				visited[i][j] =  1;
				tmp += a[i][j];
				back(i,j);
				if(ok)
				{
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
}