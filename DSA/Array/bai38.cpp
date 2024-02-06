#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = (int)1e6;

int prime[maxn +1];
int d[maxn+1];

void sang() {
    for (int i = 0; i <= maxn; i++) {
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i * i <= maxn; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                prime[j] = 0;
            }
        }
    }
}
void dem()
{
    sang();
    int cnt=0;
    for(int i=0;i<=maxn;i++)
    {
        if(prime[i])
            cnt++;
        d[i]=cnt;
    }
}
int main()
{
    int q; cin >> q;
    sang();
    dem();
    
    while(q--)
    {
        int cnt=0;
        int l, r; cin >> l >> r;
        
        cout << d[r]-d[l-1] << endl;
    }
}