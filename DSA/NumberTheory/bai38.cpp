#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = (int)1e6;
int prime[maxn +1];

void sieve() {
    memset(prime,1,sizeof(prime));
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

int leg(int n, int p)
{
	int cnt=0;
	while(n>=p)
	{
		cnt+=n/p;
		n/=p;
	}
	return cnt;
}
int main()
{
	sieve();
	int n; cin >> n;
	ll ans=1;
	ll mod = 1e9+7;
	for(int i=2;i<=n;i++)
	{
		if(prime[i])
		{
			ans*=(leg(n,i)+1);
			ans%=mod;
		}
	}
	cout << ans;
	return 0;
}