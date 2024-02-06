#include<iostream>
using namespace std;
using ll = long long;

ll m[1005][1005];

ll C(int k, int n) {
    if (k == 0 || k == n) 
        m[k][n]=1;
    else{
        if(m[k][n] == 0)
        {
             m[k][n] = C(k - 1, n - 1) + C(k, n - 1);          
        }
    }
    return m[k][n];
}
int main(){
    int n,k;

    cin >> n >> k;
    
    cout << C(n-1,k+n-1);
    return 0;
}