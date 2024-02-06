#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

ll max_area(vector<int> a, int n)
{
    stack<pair<int,ll>> st;
    ll max_area = 0;
    //{index, height}
    REP(i, 1, n)
    {
        int pos = i;
        while(!st.empty() and a[i] < st.top().second)
        {
            pos = st.top().first;
            ll h = st.top().second;
            max_area = max(max_area, h * 1ll*(i - pos));
            st.pop();
        }
        st.push({pos, a[i]});
    }
    while(!st.empty())
    {
        int pos = st.top().first;
        ll h = st.top().second;
        max_area = max(max_area, h * 1ll*(n - pos + 1));
        st.pop();
    }
    return max_area;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    faster();
    
    int n; cin >> n;
    vector<int> a(n + 1);
    REP(i, 1, n) cin >> a[i];

    cout << max_area(a, n);

}