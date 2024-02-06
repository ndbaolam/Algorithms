#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int a[N], st[4 * N];
int n, q;

void build(int id, int l, int r){
    if(l == r){
        st[id] = a[l];
        return;
    }
    int m = l + r >> 1;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);

    st[id] = max(st[2 * id], st[2 * id + 1]);
}

void update(int id, int l, int r, int i, int val){
    if(i > r || i < l) return;
    if(l == r){
        st[id] = val;
        return;
    }
    int m = l + r >> 1;
    update(2 * id, l, m, i, val);
    update(2 * id + 1, m + 1, r, i, val);

    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int get(int id, int l, int r, int u, int v){
    if(r < u || l > v) return -1;
    if(l >= u && r <= v) return st[id];

    int m = l + r >> 1;
    int m1 = get(2 * id, l, m, u, v);
    int m2 = get(2 * id + 1, m + 1, r, u, v);

    return max(m1, m2);
}

int main(){
    cin >> n;
    REP(i, 1, n) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while(q--){
        int x, y; string s; 
        cin >> s; cin.ignore();
        cin >> x >> y;
        if(s == "get-max")
            cout << get(1, 1, n, x, y) << endl;
        else update(1, 1, n, x, y);
    }
}