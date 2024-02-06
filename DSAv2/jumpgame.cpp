#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    
     for(int i = 1; i < n; i++)
      {
        a[i] = max(a[i] + i, a[i-1]);
      }
      for(int x : a)
        cout << x << ' ';
    cout << endl;
      int ind = 0;
      int ans = 0;

      while(ind < n - 1)
      {
        ans++;
        ind = a[ind];
      }

      cout << ans;
}