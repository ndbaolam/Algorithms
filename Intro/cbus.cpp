#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

int n, Q, ans, q, sum;
int a[25][25];
bool visited[25];
int x[25];

bool check(int v, int k){
  if(visited[v]) return false;
  if(v <= n){// v is pickup
    if(q >= Q) return false;
    }else{// v > N means drop-off
    if(!visited[v-n]) return false;
  }
  return true;
}

void back(int k)
{
  REP(i,1,2*n)
  {
    if(check(i, k))
    {
      x[k] = i;
      visited[i] = true;
      sum +=  + a[x[k-1]][x[k]];
      q = (i <= n) ? q + 1 : q - 1;
      if(k == 2*n) ans = min(ans, sum + a[x[2*n]][x[0]]);
      else if(sum < ans) back(k + 1);
      visited[i] = false;
      sum -=  + a[x[k-1]][x[k]];
      q = (i <= n) ? q - 1 : q + 1;
    }
  }
}

int main()
{
  scanf("%d %d", &n, &Q);
  REP(i,0,2*n) REP(j,0,2*n) scanf("%d", &a[i][j]);
  ans = 1e6;
  back(1);
  printf("%d ", ans);
}
