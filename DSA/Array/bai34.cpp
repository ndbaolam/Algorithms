#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int a[n];
    for(int &i : a)
        cin >> i;

    map <int, int> mp;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (mp.find(a[i] + k) != mp.end())
            ans = max(ans, i - mp[a[i] + k]);
        if (mp.find(a[i] - k) != mp.end())
            ans = max(ans, i - mp[a[i] - k]);
        if (mp.find(a[i]) == mp.end())
            mp[a[i]] = i;
    }
    cout << ans << "\n";
}