#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
    int n, k; cin >> n >> k;
    int f[n+1] = {0};
    f[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j ++)
        {
            if(i >= j)
            {
                f[i] += f[i - j];
                f[i] %= mod;
            }
        }
    }
    cout << f[n];
}