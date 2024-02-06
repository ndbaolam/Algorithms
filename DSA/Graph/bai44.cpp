#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

int n, m, s1, s2, t1, t2;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
char a[505][505];
string ok = "NO";

void inp()
{
  cin >> n >> m;
  REP(i,1,n) 
  {
    REP(j,1,m) 
    {
      cin >> a[i][j];
      if(a[i][j] == 'S')
      {
        s1 = i; s2 = j;
      }
      if(a[i][j] == 'T')
      {
        t1 = i; t2 = j;
      }
    }
  }
}

void back(int i, int j, int cnt, int prev)
{
  if(cnt > 3) return;
  if(i == t1 && j == t2)
  {
    ok = "YES"; return;
  }
  a[i][j] = '*';
  REP(k,0,3)
  {
    int i1 = i + dx[k], j1 = j + dy[k];
    if(i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m && a[i1][j1] != '*')
    {
      if(k == prev) back(i1, j1, cnt, k);
      else back(i1, j1, cnt + 1, k);
    }
  }
  a[i][j] = '.';
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  inp();
  back(s1,s2,0,-1);
  cout << ok << endl;
}