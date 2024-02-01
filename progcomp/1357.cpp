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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

char dig[10][3][2] = {
    {{'.', '*'}, {'*', '*'}, {'.', '.'}}, {{'*', '.'}, {'.', '.'}, {'.', '.'}},
    {{'*', '.'}, {'*', '.'}, {'.', '.'}}, {{'*', '*'}, {'.', '.'}, {'.', '.'}},
    {{'*', '*'}, {'.', '*'}, {'.', '.'}}, {{'*', '.'}, {'.', '*'}, {'.', '.'}},
    {{'*', '*'}, {'*', '.'}, {'.', '.'}}, {{'*', '*'}, {'*', '*'}, {'.', '.'}},
    {{'*', '.'}, {'*', '*'}, {'.', '.'}}, {{'.', '*'}, {'*', '.'}, {'.', '.'}}};

int main() {
  _ while (1) {
    int D;
    cin >> D;
    if (D == 0)
      break;
    char t;
    cin >> t;
    if (t == 'S') {
      string txt;
      cin >> txt;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < txt.length(); j++) {
          int aux = txt[j] - '0';
          cout << dig[aux][i][0] << dig[aux][i][1] << (j == txt.length() - 1 ? "" : " ");
        }
        cout << endl;
      }
    } else {
        vector<int> v(D);
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < D; j++){
                string st; cin >> st;
                if (st[0] == '*') v[j] |= 1 << (i * 2);
                if (st[1] == '*') v[j] |= 1 << (i * 2 + 1);
            } 
        }
        int aux[] = {-1, 1, -1, 3, -1, 2, 9, 6, -1, 5, -1, 4, -1, 8, 0, 7};
        for (auto e : v) cout << aux[e];
        cout << endl;
    }
  }
  exit(0);
}
