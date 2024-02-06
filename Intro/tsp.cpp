#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

int n, ans, cmin;
int a[25][25];
int x[25];
bool visited[25];
vector<int> tmp;
vector<int> res;

void back(int k, int sum)
{
  //cout << "k: " << k << " sum: " << sum << endl;
  REP(i,1,n)
  {
    if(!visited[i])
    {
      //cout << sum << ' ';
      visited[i] = true;
      x[k] = i;
      tmp.push_back(i);
      sum += a[x[k-1]][x[k]];
      if(k == n)
      {
        if(ans > sum + a[x[n]][x[1]])
        {
          res = tmp;
          ans = sum + a[x[n]][x[1]];
        }
      }
      else if(sum + cmin*(n-k+1) < ans) back(k + 1, sum);
      sum -= a[x[k-1]][x[k]]; 
      visited[i] = false;
      tmp.pop_back();
    }
  }
}

int main()
{
  cin >> n;
  ans = 1e9;

  REP(i,1,n) 
  {
    REP(j,1,n) 
    {
      cin >> a[i][j];
      if(i != j) cmin = min(cmin, a[i][j]);
    }
  }
  x[1] = 1; visited[1] = true;
  back(2, 0);
  cout << ans << endl;
  cout << 1 << ' ';
  for(int x : res)
    cout << x << ' ';
}