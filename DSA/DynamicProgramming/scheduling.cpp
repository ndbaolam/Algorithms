#include<bits/stdc++.h>
//#include "E:\Code\Cprograming\debug.h"
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

struct job{
  int st, ed, profit;
};

int find(vector<job>& a, int l, int r, int ref)
{
  int res = -1;
  while(l <= r)
  {
    int m = (l + r)/2;
    if(a[m].ed < ref)
    {
      res = m;
      l = m + 1;
    }
    else r = m - 1;
  }
  return res;
}  

ll f[200005];
int main()
{
  int n; cin >> n;
  vector<job> a(n);
  for(auto &x : a)
    cin >> x.st >> x.ed >> x.profit;
  sort(all(a), [](job x, job b){
    return x.ed < b.ed;
  });

  f[0] = a[0].profit;
  REP(i,1,n-1)
  {
    int j = find(a, 0, i-1, a[i].st);
    if(j != -1)
      f[i] = max(f[i-1], f[j] + a[i].profit);
    else f[i] = max(f[i-1], 1ll * a[i].profit);
  }
  //debug(f);
  cout << f[n-1] << endl;
}