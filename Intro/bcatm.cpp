#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int n;
int S;
int a[21];
int res = 99999;
 
void Try(int i , ll sum , int d){
  if (sum>S || d>res) return; 
  if(i==n){
    if (sum == S) res = min(res,d);
    return;
  }
  Try(i+1,sum,d);
  Try(i+1,sum+a[i],d+1);
}
 
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  
  cin>>n;
  cin>>S;
  for(int i=0;i<n;i++) cin>>a[i];
  Try(0,0,0);
  if (res==99999) cout<<-1;
  else cout<<res;
 
return 0;
}