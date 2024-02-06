#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const ll N = 1e6 + 7;
// 17 + 8 * 2004 - 26

int n;
ll s[N];

void read(){
    scanf("%d", &n);
    ll num[n + 1];
    ll op[n + 1];
    REP(i, 1, n) scanf("%lld", &num[i]);
    REP(i, 1, n - 1) scanf("%lld", &op[i]);

    int i = 1, j = 1, k = 1;
    while(i <= n && j <= n - 1){
        s[k++] = num[i++];
        s[k++] = op[j++];
    }
    s[k] = num[n];
    // REP(m, 1, 2*n - 1){
    //     if(m & 1) cout << "operand: " << s[m] << endl;
    // }
    // REP(m, 1, 2*n - 1){
    //     if(!(m & 1)) cout << "operator: " << s[m] << endl;
    // }
}

int priority(int x){
    if(x == 0 || x == 1) return 1;
    else return x;
}

void process_op(stack<int> &st, int op){
	
}

ll evaluate()
{
    stack<ll> st;
    stack<ll> op;

    REP(i, 1, 2*n - 1){
        if(i % 2 == 1){
            st.push(s[i]);
        }
        else{
            int cur_op = s[i];
            while(!op.empty() && priority(op.top()) >= priority(cur_op))
            {
                ll r = st.top(); st.pop();
                ll l = st.top(); st.pop();
                l %= mod; r %= mod;
                switch(op.top())
                {
                	//((l % mod) - (r % mod)) % mod
                    case 0: st.push((l - r) % mod); break;
                    case 1: st.push((l + r) % mod); break;
                    case 2: st.push((l * r) % mod); break;
                }
                op.pop();
            }
            op.push(cur_op);
        }
    }
    while(!op.empty())
    {
        ll r = st.top(); st.pop();
        ll l = st.top(); st.pop();
        switch(op.top())
        {
           	case 0: st.push((l - r) % mod); break;
            case 1: st.push((l + r) % mod); break;
            case 2: st.push((l * r) % mod); break;
        }
        op.pop();
    }
    return st.top();
}
int main()
{
    read(); 	
    printf("%lld", evaluate() );
}

