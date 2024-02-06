#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int cnt=0;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) ++cnt;
    if(cnt>=3) cout <<"YES";
    else cout <<"NO";
}