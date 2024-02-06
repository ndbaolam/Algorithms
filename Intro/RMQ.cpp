#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 5;
int a[maxn], n, q;
int t[4 * maxn];

void build(int v, int l, int r)
{
  if(l == r)
    t[v] = a[l];
  else
  {
    int m = (l + r) >> 1;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);

    t[v] = min(t[2 * v], t[2 * v + 1]);
  }
}

int get(int id, int l, int r, int u, int v) {
    if (l >  v || r <  u) return 1e9; 
    if (l >= u && r <= v) return t[id];
    
    int mid = l + r >> 1;
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);
    
    return min(get1, get2);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  faster();

  scanf("%d", &n);
  REP(i, 1, n) scanf("%d", &a[i]);
  build(1, 1, n);

  scanf("%d", &q);
  ll sum = 0;
  while(q--)
  {
    int x, y; scanf("%d %d", &x, &y);
    sum += 1ll * get(1, 1, n, x + 1, y + 1);
  }
  printf("%d", sum);
}
