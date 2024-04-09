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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int pilhas[3][110];
int dp[110][110][110];
int N;

int main() {
  _ while (1) {
    cin >> N;
    if (N == 0)
      break;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> pilhas[j][i];
        pilhas[j][i] %= 3;
      }
    }
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    dp[0][0][1] = pilhas[2][0] % 3 == 0;
    dp[0][1][0] = pilhas[1][0] % 3 == 0;
    dp[1][0][0] = pilhas[0][0] % 3 == 0;
    dp[1][1][0] = (pilhas[0][0] + pilhas[1][0]) % 3 == 0;
    dp[1][0][1] = (pilhas[1][0] + pilhas[2][0]) % 3 == 0;
    dp[0][1][1] = (pilhas[0][0] + pilhas[2][0]) % 3 == 0;
    dp[1][1][1] = (pilhas[0][0] + pilhas[1][0] + pilhas[2][0]) % 3 == 0;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        for (int k = 1; k <= N; k++) {
          dp[i][j][k] =
              (pilhas[0][i - 1] % 3 == 0) * dp[i - 1][j][k] or
              (pilhas[1][j - 1] % 3 == 0) * dp[i][j - 1][k] or
              (pilhas[2][k - 1] % 3 == 0) * dp[i][j][k - 1] or
              ((pilhas[0][i - 1] + pilhas[1][j - 1]) % 3 == 0) *
                  dp[i - 1][j - 1][k] or
              ((pilhas[0][i - 1] + pilhas[2][k - 1]) % 3 == 0) *
                  dp[i - 1][j][k - 1] or
              ((pilhas[1][j - 1] + pilhas[2][k - 1]) % 3 == 0) *
                  dp[i][j - 1][k - 1] or
              ((pilhas[0][i - 1] + pilhas[1][j - 1] + pilhas[2][k - 1]) % 3 ==
               0) *
                  dp[i - 1][j - 1][k - 1];
        }
      }
    }

    cout << (dp[N][N][N]) << endl;
  }
  exit(0);
}
