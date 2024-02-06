#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    int n; ll r=0; cin >> n; 
    ll a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll mod=1e9+7;
    sort(a,a+n);
    for(int i=0;i<n;i++){
        ll k=a[i]*i;
        r=(r+k%mod)%mod;    
    }
    cout << r;
    return 0;
}