#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

struct point{
	int x, y;
	point(int _x, int _y): x(_x), y(_y) {};
};

struct line{
	int a, b, c;
	//line(int a, int b, int c): a(a), b(b), c(c) {};
};

double dist(point a, point b){
	ll x = a.x - b.x;
	ll y = a.y - b.y;
	return sqrt(x*x + y*y);
}

ll dot_product(point o, point a, point b){
	ll xa = a.x - o.x; ll ya = a.y - o.y;
	ll xb = b.x - o.x; ll yb = b.y - o.y;
	return xa*xb + ya*yb;
}

line makeLine(point a, point b){
	line l;
	l.a = a.y - b.y;
	l.b = b.x - a.x;
	l.c = a.x*b.y - a.y*b.x;
	return l;
}

int main(){
	faster();
	point O(2, 5), A(5, 6), B(6, 2);
	double cos = dot_product(O, A, B)*1.0/(dist(O, A)*dist(O, B));
	line l = makeLine(A, B);
	cout << "cos = " << cos << endl;
	cout << l.a << "x + "  << l.b <<"y + " << l.c << " = 0" << endl;
}	