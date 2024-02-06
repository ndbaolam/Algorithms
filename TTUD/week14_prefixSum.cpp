#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n, q, a[N], pre[N];

int main(){
    cin >> n;
    REP(i, 1, n) cin >> a[i];
    pre[1] = a[1];
    REP(i, 2, n) pre[i] = pre[i - 1] + a[i];
    cin >> q;
    while(q--){
        int i, j; cin >> i >> j;
        cout << pre[j] - pre[i - 1] << endl;
    }
}