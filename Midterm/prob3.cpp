#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main() {
	faster();
    int n, m, a[101];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int d[10001] = {1};
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= m; j++) {
            d[j] += d[j - a[i]] % mod;
        }
    }
    cout << d[m] << endl;
    return 0;
}
