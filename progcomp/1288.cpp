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
    int t; cin >> t;
    while (t--){
        int N; cin >> N;
        vector<pii> v(N+1);
        for  (int i = 0; i < N; i++){
            int X, Y; cin >> X >> Y;
            v[i] = {Y, X};
        }
        int K; cin >> K;
        int R; cin >> R;
        vector<vi> dp(N+1, vi(K+1));
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= K; j++){
                dp[i][j] = dp[i-1][j];
                if (v[i-1].f <= j){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-v[i-1].f] + v[i-1].s);
                }
            }
        }
        if (dp[N][K] >= R) cout << "Missao completada com sucesso" << endl;
        else cout << "Falha na missao" << endl;
    }
    exit(0);
}
