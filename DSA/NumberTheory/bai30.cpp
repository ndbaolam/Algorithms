#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, d; cin >> n;
    int visited[d+1];
    int a[n+1];
    memset(visited,-1,n);
    for(int i=1;i<=n;i++)
    {
        int x; cin >> x;
        a[i]=x;
        visited[x]=1;
    }
    double res=0;
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        res=max(res,(double)(a[i+1]-a[i])/2);
    }
    if(visited[0]==-1)
        res=max(res,(double)a[1]);
    if(visited[d]==-1)
        res=max(res,(double)(d-a[n]));
    printf("%.10lf",res);
    return 0;
}