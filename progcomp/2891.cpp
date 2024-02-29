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

};

vector<Point> pts(5);

int cross(Point v, Point w){
    return v.x * w.y - v.y * w.x;
}

int orient(Point a, Point b, Point c){
    return cross(b-a, c-a);
}

//copied from https://victorlecomte.com/cp-geo.pdf
bool isConvex(vector<Point> &p) {
    bool hasPos=false, hasNeg=false;
    for (int i=0, n=p.size(); i<n; i++) {
        int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
        if (o > 0) hasPos = true;
        if (o < 0) hasNeg = true;
    }
    return !(hasPos && hasNeg);
}

int areaPolygon(vector<Point> &p) {
    int area = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i+1)%n]);
    }
    return area;
}

int main(){ _
    while (true){
        int ans = -INF;
        for (int i = 0; i < 5; i++) cin >> pts[i].x >> pts[i].y;
        if (pts[1].x==0 and pts[2].x==0 and pts[3].x==0 and pts[4].x==0 and pts[0].x==0) break;
        sort(pts.begin(), pts.end(), [](Point p, Point q) {
            return orient(Point{0, 0}, p, q) > 0;
        });
        for (int i = 0; i < 5; i++){
            vector<Point> aux = pts;
            aux.erase(aux.begin()+i);
            if(!isConvex(aux)) continue;
            ans=max(ans, areaPolygon(aux)/2);
        }
        cout << ans << endl;
    } 
    exit(0);
}
