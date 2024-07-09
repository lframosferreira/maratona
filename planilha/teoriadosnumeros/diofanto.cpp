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

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1300031;
const ll MAX = 2e6 + 10;

ll fat[MAX];

ll fexp(ll a, ll b) {
  if (b == 0)
    return 1;
  if (b % 2 == 0)
    return fexp(a * a % MOD, b / 2);
  return a * fexp(a, b - 1) % MOD;
}

ll inv(ll x) { return fexp(x, MOD - 2); }

ll val(int n, int c) {
  if (n == 1) {
    return 1;
  }
  return fat[n + c - 1] * inv(fat[c]) % MOD * inv(fat[n - 1]) % MOD;
}

int main() {
  _ fat[0] = 1;
  for (ll i = 1; i < MAX; i++)
    fat[i] = i * fat[i - 1] % MOD;
  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;
    cout << val(n, c) << endl;
  }
  exit(0);
}
