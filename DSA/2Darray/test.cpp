#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[101][101];

int n,m;
int ans =0;
void loang(int i, int j)
{
    ans+=a[i][j];
    // if(i== n-1 && j == m-1)
    // {
    //     cout<<ans;
    // }
    int i1= i;
    int j1= j+1;
    int i2 = i+1;
    int j2 = j;
    if(i1<n && i2<n && j1< m && j2 <m )
    {
        if(a[i1][j1]>a[i2][j2])
        {
            loang(i1,j1);
        }
        else loang(i2,j2);
    }
}
int main()
{   
    for(int i = 0 ; i <=100;i++)
    {
    for(int j = 0 ; j<=100;j++)
    {
        a[i][j]=0;
    }
}   
    cin>>n>>m;
    memset(a,0,sizeof(a));
    for(int i =0;i<n;i++)
    {
        for(int j = 0 ; j <m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i =0;i<n;i++)
    {
        for(int j = 0 ; j <m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // loang(0,0);
    // cout<<ans;
}