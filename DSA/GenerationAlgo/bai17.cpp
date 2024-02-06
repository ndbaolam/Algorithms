#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void sinh(string a, int n)
{
    int i = n-2;
    while(i>=0 && a[i]>=a[i+1])
        --i;
    if(i==-1) cout << "NOT EXIST";
    else
    {
        int j=n-1;
        while(a[i]>=a[j]) --j;
        swap(a[i],a[j]);
        reverse(a.begin()+i+1,a.end());        
        cout << a;
    }
}

int main()
{
    string a; cin >> a;
    sinh(a,a.size());
    return 0;
}