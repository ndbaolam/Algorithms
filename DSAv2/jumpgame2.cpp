#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    
    int pos=0;
    while(pos<n-1)
    {
        if(a[pos]==0) 
        {
            cout << 0;
            return 0;
        }
        pos+=a[pos];
    }
    cout << 1;
}