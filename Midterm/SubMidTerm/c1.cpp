#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int main() {
    int n;
    int mod = 1e9 + 7;
    cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    map<int,int> m;
    int res = 0;
    for(int x : a){
        res += m[1 + x];
        res += m[-1 + x];
        res %= mod;
        m[x]++;
    }
    cout << res;

    return 0;
}
