#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

int n, m, obj, ok;
vector<int> a[35]; //a[i] is the list of teachers can teach the course i
int x[35], load[35];
//x[i] is the teacher assigned to course
//load[i] is the number of course assigned to teacher i
bool conflict[35][35]; 

void inp()
{
  cin >> m >> n;
  cin.ignore();
  REP(i,1,m)
  {
    int k; cin >> k;
    REP(j,1,k)
    {
      int c; cin >> c;
      a[c].push_back(i);
    }
  }
  int k; cin >> k;
  memset(conflict, false, sizeof(conflict));
  REP(i,1,k)
  {
    int x, y; cin >> x >> y;
    conflict[x][y] = true;
    conflict[y][x] = true;
  }
}

bool check(int v, int k)
{
  REP(i,1,k-1)
    if(conflict[i][k] and x[i] == v)
      //Mon i va k trung thoi gian hoc
      //Giao vien v da dc phan cong day mon i
      return false;
  return true;
}

void back(int k)
{
  for(int v : a[k])
  {
    //Duyet tat ca giao vien co the day mon k
    if(check(v, k))
    {
      x[k] = v; load[v]++;
      if(k == n) 
      {
        ok = 1;
        int maxload = *max_element(load + 1, load + m + 1);
        obj = min(obj, maxload);
      }
      else if(load[v] < obj) back(k+1);
      load[v]--;
    }
  }
}

int main()
{
  obj = 1e6;
  inp();
  back(1);
  if(ok) cout << obj << endl;
  else cout << -1 << endl;
}
