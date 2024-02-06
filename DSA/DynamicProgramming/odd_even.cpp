#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    
    map<int,int> mp;
    mp[0] = 1;
    int ans = 0, k = 0;
    for(int i = 0; i < n; i++)    
    {
        if(a[i]&1) --k;
        else ++k;
        ans += mp[k]++;
    }
    cout << ans << endl;
}

// 1 2 1 2
// 1 0 1 0