#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Op
{
    int l, r, d;
};

typedef Op Op;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    int a[n+5]={0};
    for(int i=1;i<=n;i++)
        cin >> a[i];

    int D[n+5]={0};
    for(int i=1;i<=n;i++)
        D[i]=a[i]-a[i-1];

    Op p[m+5];
    
    for(int i=1;i<=m;i++)
    {
        int l, r, d;
        cin >> l >> r >> d;
        p[i] = {l,r,d};
        D[l]+=d;
        D[r+1]-=d;
    }

    while(k--)
    {
        int x, y; cin >> x >> y;
        for(int i=x;i<=y;i++)
        {
            D[p[i].l]+=p[i].d;
            D[p[i].r+1]-=p[i].d;
        }
    }

    for(int i=1;i<=n;i++)
        cout << D[i] + a[i-1] << " ";
}