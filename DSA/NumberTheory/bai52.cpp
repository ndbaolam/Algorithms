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
    ll x, y;
    ll a, b; cin >> a >> b;
    ll g = gcd(a, b, x, y);
    if (g != 1) {
        cout << -1;
    }
    else {
        x = (x % b + b) % b;
        cout << x << endl;
    }
}