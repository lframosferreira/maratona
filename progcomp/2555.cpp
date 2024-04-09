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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    cout << fixed << setprecision(2);
    int N, K;
    while (cin >> N >> K){
        vi premios(N+1);
        for (int i = 1; i <= N; i++) cin >> premios[i];
        vi chance(N+1);
        for (int i = 1; i <= N; i++) cin >> chance[i];
        vector<vector<double>> dp(N+1, vector<double>(K+1));
        vector<vector<double>> acumulada(N+1, vector<double>(K+1, 1.0));
        for (int i = 1; i <= N; i++) {
            dp[i][0] += dp[i-1][0] + premios[i] * (acumulada[i-1][0] * ((double)chance[i] / 100.0));
            acumulada[i][0] =  ((double)chance[i] / 100.0) *acumulada[i-1][0];
        }
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= K; j++){
                double x = dp[i-1][j] + premios[i]*(acumulada[i-1][j]*((double)chance[i] / 100.0));
                double y = dp[i-1][j-1] + (double)premios[i] * acumulada[i-1][j-1];
                if (x > y){
                    dp[i][j] += x;
                    acumulada[i][j] = ((double)chance[i] / 100.0) *acumulada[i-1][j];
                }else {
                    dp[i][j]+=y;
                    acumulada[i][j] = acumulada[i-1][j-1];
                }
            }
        }
        cout << dp[N][K] << endl;
    }
    exit(0);
}
