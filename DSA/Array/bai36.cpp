#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int &i : a)
        cin >> i;

    set<ll> s;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=1ll*a[i];
        if(sum==0)
        {
            cout << 1;
            return 0;
        }
        
        if(s.count(sum))
        {
            cout << 1; 
            return 0;
        }
        s.insert(sum);
    }
    cout << -1;
}