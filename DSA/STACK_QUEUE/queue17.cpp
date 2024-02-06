#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int a[1005][1005];
int d[1005][1005];
bool used[1005][1005];

int n, m;

void read()
{
    cin >> m >> n;
    REP(i, 1, m) REP(j, 1, n) cin >> a[i][j];
}

int bfs()
{
    queue<pii> q;
    q.push({1, 1});
    memset(d, 0, sizeof(d));
    memset(used, false, sizeof(used));
    used[1][1] = true;
    while(!q.empty())
    {
        pii top = q.front(); q.pop();
        int i = top.first, j = top.second;
        if(i == m and j == n) return d[m][n];

        if(j + a[i][j] <= n and !used[i][j + a[i][j]])
        {
            q.push({i, j + a[i][j]});
            d[i][j + a[i][j]] = d[i][j] + 1;
            used[i][j + a[i][j]] = true;
        }
        if(i + a[i][j] <= m and !used[i + a[i][j]][j]) 
        {
            q.push({i + a[i][j], j});
            d[i + a[i][j]][j] = d[i][j] + 1;
            used[i + a[i][j]][j] = true;
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
  faster();

    int q; cin >> q;
    while(q--)
    {
        read();
        cout << bfs() << endl;
    }
}