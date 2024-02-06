#include <bits/stdc++.h>
using namespace std;
#define MAX 200000
using ll = long long;

int main(){
    int n, k, q; cin >> n >> k >> q;
    int a[MAX+5]={0}; //so luong coc tra sua
    int d[MAX+5]={0}; // mang hieu cua a
    int f[MAX+5]={0};

    int l, r; 

    while(n--)
    {
    	cin >> l >> r;    	
    	++d[l];	--d[r+1];
    }

    for(int i=1;i<=MAX;i++)
    {
		a[i]=d[i]+a[i-1];
    }

    for(int i=1;i<=MAX;i++)
    {
        f[i]=f[i-1]+(a[i]>=k);
    }

    while(q--)
    {
    	cin >> l >> r;
        cout << f[r]-f[l-1] << endl;
    }
}