// pescoço pra baixo é canela
// NAO SEI PORQUE NAO FUNCIONA AAA

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Point {
    int x;
    int y;
    Point operator- (const Point &other){
        return Point{x - other.x, y - other.y};
    };
    bool operator <(const Point &other){
        if (y==other.y) return x < other.x;
        return y<other.y;
    };
};

vector<Point> pts(5);

int cross(Point v, Point w){
    return v.x * w.y - v.y * w.x;
}

int orient(Point a, Point b, Point c){
    return cross(b-a, c-a);
}

bool cmp(Point a, Point b, Point c){
    auto p1=b-a;
    auto p2=c-a;
    if (cross(p1, p2)==0){
        int d1=p1.x*p1.x+p1.y*p1.y;
        int d2 = p2.x*p2.x + p2.y*p2.y;
        return d1 < d2;
    }
    return cross(p1,p2) > 0;
}

//copied from https://victorlecomte.com/cp-geo.pdf
bool is_convex(vector<Point> &p) {
    bool turn_right=false;
    bool turn_left=false;
    int n = p.size();
    for (int i=0; i<n; i++) {
        int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
        if (o < 0) turn_right = true;
        if (o > 0) turn_left = true;
    }
    return !(turn_right and turn_left);
}

int area(const vector<Point> &p) {
    int area = 0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        area += cross(p[i], p[(i+1)%n]);
    }
    return abs(area) / 2;
}

int main(){ _
    while (true){
        int ans = -INF;
        for (int i = 0; i < 5; i++) cin >> pts[i].x >> pts[i].y;
        if (pts[1].x==0 and pts[2].x==0 and pts[3].x==0 and pts[4].x==0 and pts[0].x==0) break;
        Point mn = pts[0];
        for (int i = 1; i < 5;i++){
            if (pts[i]<mn){
                mn=pts[i];
            }
        }
        sort(pts.begin(), pts.end(), [&mn](Point p, Point q) {
            return cmp(mn, p, q);
        });
        for (int i = 0; i < 5; i++){
            vector<Point> aux = pts;
            aux.erase(aux.begin()+i);
            if(!is_convex(aux)) continue;
            ans=max(ans, area(aux));
        }
        cout << ans << endl;
    } 
    exit(0);
}
