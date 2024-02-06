#include <bits/stdc++.h>
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 105;

int n;
bool used[N][N][N];
int f[N][N][N];

int d(int w, int l, int h) {
    if(used[w][l][h]) return 0;
    int &res = f[w][l][h];
    if(res != -1) return res;   
    res = w * l * h;
    REP(i, 1, w/2) {
        res = min(res, d(i, l, h) + d(w - i, l, h));
    }
    REP(i, 1, l/2) {
        res = min(res, d(w, i, h) + d(w, l - i, h));
    }
    REP(i, 1, h/2) {
        res = min(res, d(w, l, i) + d(w, l, h - i));
    }
    return res;
}

void solve() {
    int w, l, h;
    cin >> w >> l >> h;
    memset(f, -1, sizeof(f));
    
    cin >> n;
    REP(i, 1, n) {
        int x, y, z;
        cin >> x >> y >> z;
        used[x][y][z] = true;
        used[x][z][y] = true;
        used[y][x][z] = true;
        used[y][z][x] = true;
        used[z][x][y] = true;
        used[z][y][x] = true;
    }

    cout << d(w, l, h) << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
