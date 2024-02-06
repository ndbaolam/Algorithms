#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int x[100];
int c[100][100];
int n, cmin = INT_MAX;
int ans = INT_MAX;
int visited[100];
void nhap()
{
    cin>>n;
    for(int i = 1 ; i<=n;i++)
    {
    	for(int j = 1 ; j<=n;j++)
    	{
        	cin >> c[i][j];
        	if(c[i][j])
        		cmin=min(cmin,c[i][j]);
    	}
    }
}
void back(int i, int cost)
{
    for(int j = 1 ;j<=n;j++)
    {
        if(!visited[j])
        {
            x[i]=j;
            visited[j]=1;
            cost += c[x[i-1]][x[i]];
            if(i==n)
                ans = min(ans, cost+ c[x[n]][1]);
            else if(ans > cost + (n-i+1)*cmin)
                back(i+1,cost);
            visited[j]=0;
            cost -=c[x[i-1]][x[i]];
        }
    }
}

int main()
{
    nhap();
    x[1]=1;
    visited[1]=1;
    back(2,0);
    cout<<ans;
}