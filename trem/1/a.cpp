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
    char rotulo;
    int x;
    int y;
};

int cross(Point p1, Point p2){
    return p1.x*p2.y - p1.y*p2.x;
}

int main(){ _
    int n; cin >> n;
    vector<Point> v(n);
    set<char> rotulos;
    for (int i = 0; i < n; i++){
        int x,y;cin>>x>>y;
        char rot; cin >> rot;
        v[i]={rot, x, y};
        rotulos.insert(rot);
    }
    if (rotulos.size() == n) cout << 1 << endl;
    else {
        int colineares=1;
        for (int i = 2; i < n; i++){
            int area_triangulo = v[0].x*(v[1].y-v[i].y) + v[1].x*(v[i].y-v[0].y) + v[i].x*(v[0].y - v[1].y);
            if (area_triangulo != 0){
                colineares=0;break;
            }
        }
        if (colineares) cout << 2 << endl;
        else {
            cout << "Infinito" << endl;
        }
    }
    exit(0);
}
