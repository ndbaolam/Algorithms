#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

bool check(string s, int i, int n)
{
  if(i == 0 and !isdigit(s[0]) or i == n and !isdigit(s[i]))
    return false;
  else if(s[i] == '+' and s[i-1] == '+')
    return false;
  else return true;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  faster();

  vector<int> ans;
  string s; cin >> s;
  s += '+';
  string tmp;

  ll mod = 1e9 + 7;
  int n = s.size();

  REP(i,0,n-1)
  {
    if(!check(s, i, n))
    {
      cout << "NOT_CORRECT";
      return 0;
    }
    else if(isdigit(s[i]))
    {
      tmp.push_back(s[i]);
    }
    else if(s[i] == '+')
    {
      //reverse(all(tmp));
      int k = stoi(tmp);
      k %= mod;
      ans.push_back(k);
      tmp.clear();
    }
  }
  cout << accumulate(all(ans),0);
}