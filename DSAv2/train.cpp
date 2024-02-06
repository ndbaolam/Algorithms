#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 1e9;
const ll mod = 1e9 + 7;
vector<pii> v;

void inp()
{
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  stringstream x(s1);
  stringstream y(s2);
  string tmp;
  while(x >> tmp) v.push_back({stoi(tmp),1});
  while(y >> tmp) v.push_back({stoi(tmp),-1});
}

int main()
{
  inp();
  int cnt = 0, ans = 0;
  sort(all(v), [](pii a, pii b){
    return a.fi < b.fi;
  });
  for(auto [x,y] : v)
  {
    cnt += y;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}