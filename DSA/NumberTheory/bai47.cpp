#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int d[1000005];

int ans(int a[], int max_val)
{    
    for(int i = max_val; i >= 1; i--)
    {
        int cnt=0;
        for(int j=i;j<=max_val ;j+=i)
        {
            cnt+=d[j];
            if(cnt>=2) return i;
        }
    }
    return 1;
}
int main()
{
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        d[a[i]]++;
    }
    int max_val=*max_element(a,a+n);
    cout << ans(a,max_val);
    return 0;
}