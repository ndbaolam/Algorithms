#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int n, k, goal, sum, cnt;
int a[50];

void back(int i, int pos)
{
    if(i==n+1) return;
    for(int j=pos;j<=n;j++)
    {
        if(sum+a[j]<=goal)
        {
            sum+=a[j];
            if(sum==goal) ++cnt;
            back(i+1,j+1);
            sum-=a[j];
        }
    }
}

int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];

    int sum = accumulate(a+1,a+n+1,0);
    if(sum%k!=0){
        cout << 0; 
        return 0;
    }
    goal = sum/k;
    back(1,1);
    if(cnt==k) cout << 1;
    else cout << 0;
}