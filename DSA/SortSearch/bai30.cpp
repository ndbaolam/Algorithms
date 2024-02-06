#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, d; cin >> n >> d;
    double a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    double res=0;
    for(int i=0;i<n-1;i++)
        res=max(res,(a[i+1]-a[i])/2);
    if(a[0]!=0)
        res=max(res,a[0]);
    if(a[n-1]!=d)
        res=max(res,d-a[n-1]);
    printf("%.10lf",res);
    return 0;
}