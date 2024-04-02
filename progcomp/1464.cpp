// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Point {
    int x;
    int y;

    Point operator - (const Point &other){
        return Point{x-other.x, y-other.y};
    }

    bool operator < (const Point &other){
        if (y==other.y) return x<other.x;
        return y<other.y;
    }

    bool operator == (const Point &other){
        return x==other.x and y==other.y;
    }
};

int cross(Point u, Point v){
    return u.x*v.y - u.y*v.x;
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
        if (b.x==c.x and !(b==a) and !(c==a)) return d1 > d2;
        else return d1 < d2;
    }
    return cross(p1,p2) > 0;
}

int main(){ _
    while (1){
        int N; cin >> N;
        if (N==0) break;

        vector<Point> pts(N);
        for (int i = 0; i < N; i++){
            int x, y; cin >> x >> y;
            pts[i]={x, y};
        }
        
        int cnt=0;
        while (1){

            auto it = min_element(pts.begin(), pts.end());
            Point mn_pnt = *it;
            sort(pts.begin(), pts.end(), [&mn_pnt](Point u, Point v){
                return cmp(mn_pnt, u, v);
            });

            vector<int> used_pts;
            vector<int> used_pts_mask(pts.size());
            used_pts.pb(0);
            used_pts.pb(1);
            used_pts_mask[0]=1;
            used_pts_mask[1]=1;
            int base=0;
            int prev = 1;
            int nxt = 2;
            while (1){
                if (orient(pts[base], pts[prev], pts[nxt%pts.size()]) >= 0){
                    if (nxt!=pts.size()){
                        used_pts.pb(nxt);
                        used_pts_mask[nxt]=1;
                    }
                    base=prev;
                    prev=nxt;
                    nxt++;
                    if(nxt==pts.size()) break;
                }else {
                    prev=used_pts[used_pts.size()-2];
                    base=used_pts[used_pts.size()-3];
                    used_pts_mask[used_pts.back()]=0;
                    used_pts.pop_back();
                }
            }
            
            vector<Point> new_pts;
            for (int i = 0; i < pts.size(); i++) if (used_pts_mask[i]==0) new_pts.pb(pts[i]);
            pts=new_pts;
            cnt++;
            if (pts.size()<3) break;

        }
        if (cnt%2==1) cout << "Take this onion to the lab!" << endl;
        else cout << "Do not take this onion to the lab!" << endl;
        
    }
    exit(0);
}
