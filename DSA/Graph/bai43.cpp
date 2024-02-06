#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

struct DSU{
  vector<int> par, size;

  void init(int n)
  {
    par.resize(n+5);
    size.resize(n+5,1);
    REP(i,1,n) par[i] = i;
  }
  int find(int v)
  {
    return (v == par[v]) ? v : par[v] = find(par[v]);
  }
  void join(int a, int b)
  {
    a = find(a); b = find(b);
    if(a == b) return;
    if(size[a] < size[b]) swap(a,b);
    par[b] = a;
    size[a] += size[b];
  }
} dsu;
int n, m, ans;
void solve(int x, int y)
{
  if(dsu.find(x) != dsu.find(y))  
  {
    --n;
    dsu.join(x, y);
    ans = max(ans, dsu.size[dsu.find(x)]);
  }
  cout << n << ' ' << ans << endl;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m;
  dsu.init(n);
  REP(i,1,m)
  {
    int x, y; cin >> x >> y;
    int ans = 1;
    solve(x, y);
  }
}