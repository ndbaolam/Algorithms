/*Cho mảng số nguyên A[] gồm N phần tử và số nguyên dương S
Nhiệm vụ của bạn hãy xác định xem có thể tạo ra một tập
con các phần tử trong mảng có tổng bằng S hay không?
Chú ý mỗi phần tử trong mảng chỉ được sử dụng một lần.*/

#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
    string x, y; cin >> x >> y;
    int n = x.size(), m = y.size();
    int f[n+1][m+1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0) f[i][j] = 0;
            else
            {
                if(x[i-1] == y[j-1]) f[i][j] = f[i-1][j-1] + 1;
                else
                    f[i][j] = max(f[i][j-1], f[i-1][j]);
            }
        }
    }
    cout << f[n][m] << endl;
}