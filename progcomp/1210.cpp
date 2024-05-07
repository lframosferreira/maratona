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
typedef vector<double> vd;
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, I, M, P;

// do ij é custo minimo so no dia i idade é j

int main(){ _
    while (cin >> N >> I >> M >> P){
        vi custo(M); for (int i = 0; i < M; i++) cin >> custo[i];
        vi venda(M+1); for (int i = 1; i <= M; i++) cin >> venda[i];
        vvi dp(N+1, vi(M+1));
        for (int i = 1; i <= M; i++){
            dp[N][i] = -venda[i];
        }
        for (int i = 1; i < N; i++){
            for (int j = 1; j < M; j++){
                if (j==M){
                    dp[i][j]=dp[i+1][1]-venda[M];
                    continue;
                }
                // vendi
                int x = dp[i+1][1] - venda[i];
                // nao vendi
                int y = dp[i+1][j+1] + custo[i];
                if (x <= y){
                    dp[i][j]=x;
                }else {
                    dp[i][j]=y;
                }
            }
        }
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    } 
    exit(0);
}
