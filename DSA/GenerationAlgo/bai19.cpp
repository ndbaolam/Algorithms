#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, final;

void sinh(string &a)
{
    int i=n-1;
    while(i>=0 && a[i]=='1')
    {        
        a[i]='0';
        --i;
    }
    if(i==-1) final=1;
    else
        a[i]='1';
}

int main()
{
    cin >> n;
    n/=2;
    vector<string> res;

    while(n)
    {
        string a(n,'0');
        while(!final)
        {
            res.push_back(a);
            sinh(a);
        }
        --n;
        final=0;
    }
   
    for(auto &i : res)
    {
        string tmp=i;
        reverse(i.begin(),i.end());
        i=tmp+i;
    }
    sort(res.begin(),res.end());
    for(auto i : res)
        cout << i << endl;
    return 0;
}