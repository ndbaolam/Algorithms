#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, x[20], ans, m;

void back(int k, int pos, int sum){
    if(sum > m || k > n + 1) return;

    if(k == n + 1){
        if(sum == m){
            REP(j, 1, n) cout << x[j] << ' ';
            cout << endl;
            ++ans;
        }
        return;
    }

    REP(i, pos, m){
        x[k] = i;
        back(k + 1, i + 1,  sum + i);
    }
}

int main(){
    cin >> n >> m;
    //REP(i, 1, n) cin >> a[i];
    back(1, 1, 0);
    cout << ans;
}