// pescoço pra baixo é canela
// ADD SOME KIND OF SPECIAL LAZY PROPRAGATION TO AVOID TLE

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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;

struct node {
  int v[10];
  node() { memset(v, 0, sizeof v); }
  struct node operator+(const struct node &other) {
    struct node node2;
    for (int i = 0; i <= 9; i++)
      node2.v[i] = v[i] + other.v[i];
    return node2;
  }
};

int nums[MAX];
node seg[4 * MAX];

node build(int p, int l, int r) {
  if (l == r) {
    seg[p].v[nums[l]] = 1;
    return seg[p];
  }
  int m = (l + r) / 2;
  auto a = build(2 * p, l, m);
  auto b = build(2 * p + 1, m + 1, r);
  return seg[p] = a + b;
}

node query(int a, int b, int p, int l, int r) {
  if (b < l or r < a)
    return NULL;
  if (l >= a and r <= b)
    return seg[p];
  int m = (l + r) / 2;
  return query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r);
}

struct node update(int i, int x, int p, int l, int r) {
  if (i < l or r < i)
    return seg[p];
  if (l == r)
    return seg[p] = x;
  int m = (l + r) / 2;
  return seg[p] = update(i, x, 2 * p, l, m) + update(i, x, 2 * p + 1, m + 1, r);
}

int main() {
  _ int N;
  cin >> N;
  memset(seg, 0, sizeof seg);
  for (int i = 0; i < N; i++)
    nums[i] = 1;
  build(1, 0, N - 1);
  int Q;
  cin >> Q;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    struct node aux = query(a, b, 1, 1, N);
    int mx = 0, f;
    for (int i = 9; i >= 0; i--) {
      if (aux.v[i] > mx) {
        mx = aux.v[i];
        f = i;
      }
    }
    update(a, b, 1, 1, N);
  }
  for (int i = N; i < 2 * N; i++) {
    int ret;
    for (int j = 0; j <= 9; j++)
      if (seg[i].v[j]) {
        ret = j;
        break;
      }
    cout << ret << endl;
  }
  exit(0);
}
