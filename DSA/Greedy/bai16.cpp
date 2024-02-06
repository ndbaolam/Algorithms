#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

void Try(ll tu, ll mau){
    if(mau % tu == 0){
        cout << "1/" << mau / tu << endl; return;
    }
    ll c = mau / tu + 1;
    cout << "1/" << c << " + ";
    ll mc = mau * c;
    ll tumoi = c * tu - mau;
    Try(tumoi, mc);
}

int main()
{	
	ll p, q; cin >> p >> q;
	Try(p,q);
}