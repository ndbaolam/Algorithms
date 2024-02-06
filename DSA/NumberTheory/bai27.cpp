#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()

#define int long long
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e7 + 1e5;

bool isPalin(int x) {
    int X = x;
    int rx = 0;
    while (X) {
        rx = rx * 10 + X % 10;
        X /= 10;
    }
    return (x == rx);
}

bool isValid(int x) {
    int cnt = 0;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            ++cnt;
        }
    }
    if (x != 1)
         cnt++;
    return (cnt >= 3);
}

signed main() {
    int l, r;
    cin >> l >> r;
    bool none = 1;
    for (int i = l; i <= r; ++i) {
        if (isPalin(i) && isValid(i)) {
            cout << i << " ";
            none = 0;
        }
    }
    if (none) cout << "-1\n";
}