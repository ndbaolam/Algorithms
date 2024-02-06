#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,a,b) for(int i = a; i <= b ; i++)
ll f[100005][105];
int main()
{
    int mod = 1e9 + 7;
    int n, m; cin >> n >> m;
    int a[n+1];
    REP(i,1,n) cin >> a[i];

    if(a[1] != 0) f[1][a[1]] = 1;
    else REP(i,1,m) f[1][i] = 1;
    
    REP(i,2,n)
    {
        if(a[i] != 0)
        {
            f[i][a[i]] = f[i-1][a[i]-1] + f[i-1][a[i]] + f[i-1][a[i]+1];
            f[i][a[i]] %= mod;
        }
        else
        {
            REP(j,1,m)
            {
                f[i][j] = f[i-1][j] + f[i-1][j-1] + f[i-1][j+1];
                f[i][j] %= mod;
            }
        }
    }
    ll res = 0;
    REP(i,1,m) 
    {
        res += f[n][i];
        res %= mod;
    }
    cout << res;
}