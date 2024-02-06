#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e6;

int n, q;
int a[N], st[N];

void build(int id, int l, int r)
{
  if(l == r) st[id] = a[l];
  else
  {
    int m = l + r >> 1;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);
    st[id] = min(st[2 * id], st[2 * id + 1]);
  }
}

int get(int id, int l, int r, int x, int y)
{
  if(l > y or r < x) return 1e9;
  if(l >= x and r <= y) return st[id];

  int m = l + r >> 1;
  int get1 = get(2 * id, l , m, x, y);
  int get2 = get(2 * id + 1, m + 1, r, x, y);

  return min(get1, get2);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  faster();
  
  cin >> n >> q;
  REP(i, 1, n) cin >> a[i];
  build(1, 1, n);
  while(q--)
  {
    int x, y; cin >> x >> y;
    cout << get(1, 1, n, x, y) << endl;
  }
}