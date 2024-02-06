#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
using ll = long long;
int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<ll> ans;
    ans.push_back(a[0]);
    for(int i = 1; i < n; i++)
    {
        if(a[i] > ans.back()) ans.push_back(a[i]);
        else
        {
            int pos = lower_bound(all(ans),a[i]) - ans.begin();
            ans[pos] = a[i];
        }
    }
    cout << ans.size();
}