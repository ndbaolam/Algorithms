#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[7];
void init()
{
    a[0]=11;
    for(int i=1;i<7;i++)
        a[i]=a[i-1]*10+1;
}

int main()
{
    init();
    ll n; cin >> n;
    int i=6;
    while(n && i>=0)
    {
        if(n-a[i]<0)
            --i;
        else
        {
            while(n-a[i]>0)
                n-=a[i];
        }
    }
    if(n==0)
        cout <<"YES";
    else cout <<"NO";
    return 0;
}