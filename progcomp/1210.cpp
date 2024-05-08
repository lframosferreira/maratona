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
typedef pair<int , int> ii;
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
        vvi vendeu(N+1, vi(M+1));
        dp[N][M]=-venda[M]+P+custo[0];
        vendeu[N][M]=1;
        for (int i = 0; i < M; i++){
            int x = -venda[i]+custo[0]+P;
            int y = custo[i];
            if (x<= y){
                vendeu[N][i]=1;
                dp[N][i]=x;
            }else {
                dp[N][i]=y;
            }
        }
        for (int i = N-1; i>=1; i--){
            for (int j = M; j >= 1; j--){
                // vendi
                int y =INF;
                int x = dp[i+1][1] - venda[j] + custo[0]+P;
                // nao vendi
                if (j < M) y = dp[i+1][j+1] + custo[j];
                if (x <= y){
                    vendeu[i][j]=1;
                    dp[i][j]=x;
                }else {
                    dp[i][j]=y;
                }
            }
        }
        cout << dp[1][I] << endl;
        int mudou_algm_vez=0;
        for(int a = 1, b=I;a <=N; a++){
            if (vendeu[a][b]){
                if (mudou_algm_vez) cout << " ";
                mudou_algm_vez=1;
                cout << a;
                b=1;// checamos desde o começo
            }else b++;
        }
        if (!mudou_algm_vez) cout << 0;
        cout << endl;
    } 
    exit(0);
}
