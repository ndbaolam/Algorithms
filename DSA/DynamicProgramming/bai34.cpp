#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
    int n; cin >> n;
    vector<int> a(n), f;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> pre(n,0), pos(n,0);
    pre[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1])
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = 1;
    }
    pos[n-1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1])
            pos[i] = pos[i + 1] + 1;
        else
            pos[i] = 1;
    }

    ll l = 1, ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1])
            l++;
        else
            l = 1;
        ans = max(ans, l);
    }
    for (int i = 1; i <= n - 2; i++)
        if (a[i - 1] < a[i + 1])
            ans = max(pre[i - 1] + pos[i + 1], ans);

    cout << ans << endl;

    for(int i = 0; i < n; i++)
    	cout << pos[i] << ' ';
    cout << endl;
    for(int i = 0; i < n; i++)
    	cout << pre[i] << ' ';
}