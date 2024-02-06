#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define pii pair<int,int>
using namespace std;
using ll = long long;

using namespace std;
 
int n,  m;
int a[100005];
 
int count(int i, int j, int x){
    int res = 0;
    int l = i, r = j;
    while(l < r){
        if(a[l] + a[r] == x){
            if(a[l] == a[r]){
                res += (r - l) * (r - l + 1) / 2;
                break;
            }
            res++;
            l++;
            r--;
        }
        else if(a[l] + a[r] < x) l++;
        else r--;
    }
    return res;
}
 
int main()
{
    int res = 0;
    cin >> n >> m;
    REP(i, 1, n)
        cin >> a[i];
    sort(a+1, a+n+1);
    REP(i, 1, n){
        res += count(i+1, n, m - a[i]);
    }
    cout<<res;
    return 0;
}
