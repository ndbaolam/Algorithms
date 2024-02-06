#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = (int)1e6;
int prime[maxn +1];

void sieve() {
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

int main()
{
	sieve();
	ll n; cin >> n;
	int cnt=0;
	for(int i=1;i<=sqrt(n);i++)
		if(prime[i])
			cnt++;
	cout << cnt;
}