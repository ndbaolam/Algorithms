#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[105][105];
ll F[105][105];
int n,m;
int ans =0;
void nhap(){
    cin>>n>>m;
    for(int i =1 ; i <= n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
}

int main()
{
    nhap();
    for(int i =1; i <= n;i++)
    {
        for(int j =1 ; j<=m;j++)
        {
            F[i][j] = max(F[i-1][j],F[i][j-1])+a[i][j];
        }
    }
    cout<<F[n][m];
}