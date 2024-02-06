#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m, timer;
int disc[1005], low[1005];

vector<int> ke[1005];

bool visited[1005], AP[1005];
int dem = 0;

void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(AP, false, sizeof(visited));
}
void DFS(int u, int par){
    disc[u] = low[u] = ++timer;
    visited[u] = true;
    int child = 0;
    for(int v : ke[u]){
        if(v == par) continue;
        if(!visited[v]){
            ++child;

            DFS(v, u);

            low[u] = min(low[u], low[v]);
            
            if(par != -1 && low[v] >= disc[u]){
                AP[u] = true;
            }
            
        }
        else{
            low[u] = min(low[u], disc[v]);
        }
    }
    if(par == -1 && child > 1) AP[u] = true;
}

int main(){
    nhap();
    int dem = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS(i, -1);
        }
    }
    for(int i = 1; i <= n; i++){
        if(AP[i]) ++dem;
    }
    cout << dem << endl;
}