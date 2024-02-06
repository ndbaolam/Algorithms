#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{    
    int n, s; cin >> n >> s;
    vector<int> a(n);
    vector<int> f(s + 1, 0);
    f[0] = 1;
    for(int &x : a) cin >> x;
    for(int x : a)
    {
        for(int i = s; i >= x; i--)
        {
            if(f[i - x]) f[i] = 1;
        }
    }
    cout << f[s];
}