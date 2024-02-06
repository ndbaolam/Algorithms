#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

const int maxn = (int)1e6;
int prime[maxn +1];
ll f[maxn+1];

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

void init()
{
	f[2] = 1;
	for(int i = 3; i <= maxn; i++)
	{
		if(prime[i])
			f[i] = f[i - 1] + 1;
		else f[i] = f[i - 1];
	}
}

int main()
{
	int t; cin >> t;
	sieve(1;)
	init();
	while(t--)
	{
		int n; cin >> n;
		cout << f[n] << endl;
	}
}