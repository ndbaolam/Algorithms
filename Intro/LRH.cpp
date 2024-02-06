#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int getMaxArea(int a[], int n) 
{ 
  vector<pii> s; // {idx, height}
  int area = 0;
  REP(i, 0, n - 1)
  {
    int st = i;
    while(!s.empty() and s.back().second > a[i])
    {
      int idx = s.back().first, h = s.back().second;
      area = max(area, h * (i - idx));
      st = idx;
      s.pop_back();
    }
    s.push_back({st, a[i]});
  }
  for(auto [i, h] : s)
    area = max(area, h * (n  - i));
  return area;
} 
  
int main() 
{ 
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  faster();

  int n; cin >> n;
  int a[n]; for(int &x : a) cin >> x;

  cout << getMaxArea(a, n) << endl; 
    return 0; 
} 
  