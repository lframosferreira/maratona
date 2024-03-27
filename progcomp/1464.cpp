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

    Point operator - (const Point& other){
        return {x-other.x, y-other.y};
    }

    bool operator < (const Point& other){
        if (y==other.y) return x<other.x;
        return y<other.y;
    }
};

int cross(Point u, Point v){
    return u.x*v.y - u.y*v.x;
}

int orient(Point a, Point b, Point c){
    return cross(b-a, c-a);
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
        
        Point mn_pnt = *min_element(pts.begin(), pts.end());

        sort(pts.begin(), pts.end(), [](Point u, Point v){
            return orient(mn_pnt, u, v);
        });
        
        for (auto pt: pts){
            cout << pt.x << "," <<  pt.y << " ";
            cout << endl;
        }

        int cnt=0;
        if (cnt%2==1) cout << "Take this onion to the lab!" << endl;
        else cout << "Do not take this onion to the lab!" << endl;
    }
    exit(0);
}
