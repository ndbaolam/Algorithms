#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int n, m, ok;
char a[100][100];
int visited[100][100];
string s, tmp="";

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

void nhap()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	cin >> s;
}

void back(int i, int j)
{
	if(ok || tmp==s) 
	{	
		ok=1;
		return;
	}

	for(int k=0;k<4;k++)
	{
		int i1 = i+dx[k];
		int j1 = j+dy[k];
		if(i1 >=1 && i1 <=n && j1 >= 1 && j1 <= m && !visited[i1][j1])
		{
			tmp+=a[i1][j1];
			visited[i1][j1]=1;
			if(tmp==s) ok =1;
			else if(s.find(tmp)!=string::npos)
				// kiem tra xau con
				back(i1,j1);
			tmp.pop_back();
			visited[i1][j1]=0;
		}
	}
}

int main()
{
	nhap();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==s[0]) 
			{
				tmp="";
				tmp+=a[i][j];
				visited[i][j]=1;
				back(i,j);
				if(ok) 
				{
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
}