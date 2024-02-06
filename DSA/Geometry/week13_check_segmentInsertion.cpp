// A C++ program to check if two given line segments intersect 
#include <bits/stdc++.h> 
using namespace std; 

struct Point 
{ 
    int x; 
    int y; 
    Point(int x, int y): x(x), y(y) {};
}; 

bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
    return true; 

    return false; 
} 

int orientation(Point p, Point q, Point r) 
{ 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    int val = (q.y - p.y) * (r.x - q.x) - 
            (q.x - p.x) * (r.y - q.y); 

    if (val == 0) return 0; // colinear 

    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
// Driver program to test above functions 

bool check(Point A, Point B, Point C){
    return (orientation(A, B, C) == 0) and onSegment(B, A, C);
}
int main() 
{ 
    int n; cin >> n;
    while(n--){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Point A(x1, y1), B(x2, y2), C(x3, y3);
        cout << check(A, B, C) << endl;
    }
    return 0; 
} 