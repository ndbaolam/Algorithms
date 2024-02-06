#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair <int,int>;

const int INF = 1e9;
const int MAX = 1e9+5;
const ll mod = 1e9+7;

int n, cnt, res=1e9;
ll s;
ll a[100], x[100];

void ql(int i, int pos, ll sum)
{
    for(int j=pos;j<=n;j++)
    {
        if(sum+a[j] <= s)
        {
            x[i]=a[j];
            if(sum+x[i]==s)
            {
                res=min(res,i);
            }
            else ql(i+1,j+1,sum+x[i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    ql(1,1,0);
    if(res==1e9) cout << -1;
    else cout << res;
}