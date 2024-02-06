#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool prime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return n>1;
}

int digit(int n)
{
    int sum=0;
    while(n!=0)
    {
        int x = n%10;
        sum+=x;
        if(x!=2 && x!=3 && x!=5 && x!=7)
            return 0;
        n/=10;
    }
    return prime(sum);
}
int main()
{
    int a, b; cin >> a >> b;
    int cnt=0;
    for(int i=a;i<=b;i++)
    {
        if(digit(i) && prime(i))
            cnt++;
    }
    cout << cnt;
}