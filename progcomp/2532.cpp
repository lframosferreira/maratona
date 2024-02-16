// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int N, P;
    while (cin >> N >> P){
        vector<pii> v(N+1);
        for (int i = 0; i < N; i++){
            int D, M; cin >> D >> M;
            v[i] = {D, M};
        }
        vector<vi> dp(N+1, vi(P+1, INF));
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= P; j++){
                dp[i][j] = dp[i-1][j];
                if (v[i-1].f <= j){
                    dp[i][j] = min(dp[i][j], dp[i-1][j - v[i-1].f] + v[i-1].s);
                }
                else dp[i][j] = 0;
            }
        }
        
        cout << dp[N][P] << endl;
    }
    exit(0);
}
