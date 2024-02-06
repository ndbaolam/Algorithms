#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int maxN = 1e5 + 7;

int n, q;
int a[maxN];
ll st[4 * maxN];

void update(int id, int l, int r, int x, int y)
{
  if(l > x or r < x) return;
  if(l == r) 
  {
    st[id] = 1ll * y;
    return;
  }

  int m = l + r >> 1;
  update(2 * id, l, m, x, y);
  update(2 * id + 1, m + 1, r, x, y);

  st[id] = st[2 * id] + st[2 * id + 1];
}

ll get(int id, int l, int r, int x, int y)
{
  if(l > y or r < x) return 0;
  if(l >= x and r <= y) return st[id];

  int m = l + r >> 1;
  ll get1 = get(2 * id, l, m, x, y);
  ll get2 = get(2 * id + 1, m + 1, r, x, y);

  return get1 + get2;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  faster();
  
  cin >> n >> q; 
  while(q--)
  {
    int op, x, y; cin >> op >> x >> y;
    if(op == 1)
      update(1, 1, n, x, y);
    else if(op == 2)
      cout << get(1, 1, n, x, y) << endl;
  }
}