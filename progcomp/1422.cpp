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

const int MOD = 13371337;

struct Matrix {
  ll m[4][4];
  Matrix operator*(const Matrix &other) {
    Matrix ret{{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          ret.m[i][k] += m[i][j] * other.m[j][k]%MOD;
          ret.m[i][k] %= MOD;
        }
      }
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        os << mat.m[i][j] << " ";
      }
      os << endl;
    }
    return os;
  }
};

Matrix fexp(struct Matrix a, ll b) {
  struct Matrix res = {
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

int main() {
  _ ll n;
  for (;;) {
    cin >> n;
    if (!n)
      break;
    ll a[5];
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    struct Matrix ma = {
        {{1, 1, 1, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}}};
    ma = fexp(ma, n - 4);
    ll ans = 0;
    for (int i = 1; i <= 4; i++)
      for (int j = 0; j < 4; j++) {
        ans =(ans%MOD + (a[5-i] * ma.m[j][i - 1]%MOD) % MOD)%MOD;
      }
    cout << ans%MOD << endl;
  }
  exit(0);
}
