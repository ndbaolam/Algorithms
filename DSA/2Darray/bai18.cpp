#include <bits/stdc++.h>
using namespace std;
#define MAX 105

int a[MAX][MAX];
int n, m;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void nhap()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
}

void loang()
{
    int cnt=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            bool check = true;
            for(int k=0;k<8;k++)
            {
                int i1 = i + dx[k];
                int j1 = j + dy[k];
                if(a[i][j]<=a[i1][j1])
                {                    
                    check = false;
                    break;
                }
            }
            if(check) cnt++;
        }
    }
    cout << cnt;
}

int main()
{
    nhap();
    loang();
}