#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n, ans;
int a[N], p[N], res[N];
bool flag[N];

struct DSU{
  vector<int> parent, size, sum;
  DSU(int n) : parent(n), size(n), sum(n) {};
  // DSU(int n)
  // {
  //   parent.resize(n);
  //   size.resize(n);
  //   sum.resize(n);
  // }

  void init(int n)
  {
    REP(i,1,n)
    {
      parent[i] = i;
      size[i] = 1;
      sum[i] = a[i];
    }
  }

  int find(int v)
  {
    return (v == parent[v]) ? v : find(parent[v]);
  }

  void join(int a, int b)
  {
    a = find(a); b = find(b);
    if(a != b)
    {
      if(size[a] < size[b]) swap(a,b);
      parent[b] = a;
      size[a] += size[b];
      sum[a] += sum[b];
    }
  }
};

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  REP(i,1,n) cin >> a[i];
  REP(i,1,n) cin >> p[i];

  DSU g(n+5);
  g.init(n);
  DREP(i,n,1)
  {
    flag[p[i]] = true;

    if(p[i] > 1 && flag[p[i] - 1]) g.join(p[i], p[i] - 1);
    if(p[i] < n && flag[p[i] + 1]) g.join(p[i], p[i] + 1);

    ans = max(ans, g.sum[g.find(p[i])]);
    res[i - 1] = ans;
  }
  REP(i,1,n) cout << res[i] << endl;
}