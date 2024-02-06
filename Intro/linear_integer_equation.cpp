#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

int n, m; 
int x[20];
vector<vector<int>> res;

void back(int i, int sum)
{
  REP(j,1,m)
  {
    if(sum + j <= m)
    {
      x[i] = j;
      sum += j;
      if(sum == m && i == n)
      {
        vector<int> tmp(x + 1, x + n + 1);
        res.push_back(tmp);
      }
      else back(i+1, sum);
      sum -= j;
    }
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m;
  back(1, 0);
  for(auto x : res)
  {
    for(int y : x)
      cout << y << ' ';
    cout << endl;
  }
}