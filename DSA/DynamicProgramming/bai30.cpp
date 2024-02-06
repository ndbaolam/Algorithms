#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b ; i++)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
int f[505][505];

int solve(int n, int m)
{
    if(n == m) return 0;
    int res = 1e9;
    if(f[n][m]) return f[n][m];
    REP(j,1,m-1)
        res = min(res, solve(n, j) + solve(n, m-j) + 1);
    REP(i,1,n-1)
        res = min(res, solve(i, m) + solve(n-i, m) + 1);
    return f[n][m] = res;
}

int main()
{
    int n, m; cin >> n >> m;
    cout << solve(n,m);
}