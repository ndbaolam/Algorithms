#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int final;
ll a[305];
vector<ll> res;

void sinh(string &s)
{
    int i = s.length()-1;
    while(i>=0 && s[i]=='8')
    {        
        s[i]='0';
        --i; 
    }
    if(i==-1) final=1;
    else
        s[i]='8';
}

void prepare()
{
    string s(19,'0');
    sinh(s);
    while(!final)
    {
        res.push_back(stoll(s));
        sinh(s);
    }
    for(int i=1;i<=300;i++)
    {
        for(ll x : res)
            if(a[i]==0 && x%i==0)
                a[i]=x;
    }
}
int main()
{
    prepare();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}