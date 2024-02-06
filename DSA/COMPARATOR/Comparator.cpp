#include <bits/stdc++.h>
using namespace    std;


int chan(int a)
{
    int count=0;
    while(a)
    {
        int b = a%10;
        if(b%2==0)
            count++;
        a/=10;
    }
    return count;
}
bool cmp1(int a, int b)
{
    if(chan(a)!=chan(b))
        return chan(a)<chan(b);
    else return a<b;
}

int le(int a)
{
    int count=0;
    while(a)
    {
        int b = a%10;
        if(b%2!=0)
            count++;
        a/=10;
    }
    return count;
}

bool cmp2(int a, int b)
{
        return le(a)<le(b);
}
int main()
{
    int N; cin >> N;
    vector<int> v, c;
    for(int i=0;i<N;i++)
    {
        int x; cin >> x;
        v.push_back(x);
        c.push_back(x);
    }

    sort(v.begin(),v.end(),cmp1);
    for(int i :v)
        cout << i << " ";
    cout << endl;
    stable_sort(c.begin(),c.end(),cmp2);
    for(int i:c)
        cout << i << " ";
}