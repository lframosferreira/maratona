// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define endl '\n'
#define sz(v) (int)v.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 110;

struct Point {
  double x;
  double y;
};

double dist(const Point &p1, const Point &p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

struct Circle {
  Point center;
  double r;

  bool contains(const Point &p) { return dist(p, center) <= r; }
};

int n;
Point P[MAX];
vector<Point> R_global;

Circle aaa(const vector<Point> &R) { return {{0.0, 0.0}, 0.0}; }

Point get_circle_center(double bx, double by, double cx, double cy) {
  double B = bx * bx + by * by;
  double C = cx * cx + cy * cy;
  double D = bx * cy - by * cx;
  return {(cy * B - by * C) / (2 * D), (bx * C - cx * B) / (2 * D)};
}

// Function to return a unique circle that
// intersects three points
Circle trivial(const Point &A, const Point &B, const Point &C) {
  Point I = get_circle_center(B.x - A.y, B.y - A.y, C.x - A.x, C.y - A.y);

  I.x += A.x;
  I.y += A.y;
  return {I, dist(I, A)};
}

Circle welzl(int m, vector<Point> &R) {
  if (m == 0) {
    return {{0.0, 0.0}, 0.0};
  }
  if (sz(R) == 3) {
    return trivial(R[0], R[1], R[2]);
  }
  // choose randomly, I am selecting tha last one
  Circle D = welzl(m-1,R);
  // i am indezing P with the decremented m cause of staring index 0,possiblr
  // bugs here
  if (D.contains(P[m-1])) {
    return D;
  }
  R.pb(P[m-1]);
  return welzl(m-1, R);
}

int main() {
  int cnt = 1;
  _ while (cin >> n) {
    if (n == 0)
      break;
    memset(P, 0, sizeof P);
    R_global.clear();
    for (int i = 0; i < n; i++) {
      cin >> P[i].x >> P[i].y;
    }
    Circle ans = welzl(n, R_global);
    cout << "Instancia " << cnt << endl;
    cout << ans.center.x << " " << ans.center.y << " " << ans.r << endl;
    cout << endl;
    cnt++;
  }
  exit(0);
}
