#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int R, C;
int A[1005][1005];

int maxR(int row[])
{
  stack<int> s;
  int max_area = 0;
  int area = 0;
  int i = 0;
  while (i < C) {
    if (s.empty() || row[s.top()] <= row[i])
      s.push(i++);

    else {
      int top = row[s.top()];
      s.pop();
      area = top * i;

      if (!s.empty())
        area = top * (i - s.top() - 1);
      max_area = max(area, max_area);
    }
  }

  while (!s.empty()) {
    int top = row[s.top()];
    s.pop();
    area = top * i;
    if (!s.empty())
      area = top * (i - s.top() - 1);

    max_area = max(area, max_area);
  }
  return max_area;
}

int rectangel()
{
  int res = maxR(A[0]);

  REP(i,1,R-1)
  {
    REP(j,0,C-1)
      if (A[i][j])
        A[i][j] += A[i - 1][j];
    res = max(res, maxR(A[i]));
  }
  return res;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  faster();

  cin >> R >> C;
  REP(i,0,R-1) REP(j,0,C-1) cin >> A[i][j];
  cout << rectangel();

  return 0;
}
