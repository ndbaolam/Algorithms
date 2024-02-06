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
int a[505][505];
bool visited[505][505];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

struct node {
    int i, j, dist;
    node(int i, int j, int dist) : i(i), j(j), dist(dist) {}
    bool operator<(const node& other) const {
        return dist > other.dist;
    }
};

void inp()
{
  cin >> n >> m;
  REP(i,1,n) REP(j,1,m) cin >> a[i][j];
}

int dijkstra()
{
  priority_queue<node> Q;
  Q.push(node(1,1,a[1][1]));
  while(!Q.empty())
  {
    node top = Q.top(); Q.pop();
    if(visited[top.i][top.j]) continue;

    visited[top.i][top.j] = true;
    if(top.i == n and top.j == m) return top.dist;

    REP(k,0,3)
    {
      int i1 = top.i + dx[k], j1 = top.j + dy[k];
      if(i1 >= 1 and j1 >= 1 and i1 <= n and j1 <= m and !visited[i1][j1])
        Q.push(node(i1, j1, top.dist + a[i1][j1]));
    }
  }
  return -1;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  inp();
  cout << dijkstra();
}