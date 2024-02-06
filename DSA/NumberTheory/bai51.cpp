#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    ll m, n, p, x, y;
    cin >> m >> n >> p;
    ll g = gcd(m,n,x,y);
    if((x+y)&1) cout << "NO";
    else cout << "YES";
    return 0;
}