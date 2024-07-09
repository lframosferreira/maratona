// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ull MOD = 1e6;

struct Matrix {
  ull m[2][2];
  Matrix operator*(const Matrix &other) {
    Matrix ret{{{0, 0}, {0, 0}}};
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          ret.m[i][k] += m[i][j] * other.m[j][k] % MOD;
          ret.m[i][k] %= MOD;
        }
      }
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        os << mat.m[i][j] << " ";
      }
      os << endl;
    }
    return os;
  }
};

Matrix fexp(struct Matrix a, ll b) {
  struct Matrix res = {{{1, 0}, {0, 1}}};
  while (b) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

int main() {
  _ ull N, K, L;
  while (cin >> N >> K >> L) {
    struct Matrix mat = {{{0, L%MOD}, {1, K%MOD}}};
    mat = fexp(mat, N / 5);
    ull ans = mat.m[0][0] + (K%MOD * mat.m[1][0]) % MOD;
    cout << setfill('0') << setw(6) << ans % MOD << endl;
  }
  exit(0);
}
